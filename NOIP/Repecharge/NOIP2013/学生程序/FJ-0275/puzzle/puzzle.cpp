#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
#define INF 1000000
struct node
{
	int x,y,count;
	int sx,sy;
};
map<long long,bool>hash;
int N,M;
node E,S,T,t,temp;
bool Map[50][50];

void init()
{
	int make_map;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&make_map);
			Map[i][j]=make_map?1:0;
		}
	/*
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)cout<<Map[i][j]<<' ';
		cout<<endl;
	}
	*/
}

void solve()
{
	int ans=0;hash.clear();
	
	queue<node>Q;
	scanf("%d%d%d%d%d%d",&E.x,&E.y,&S.x,&S.y,&T.x,&T.y);
	//cin>>E.x>>E.y>>S.x>>S.y>>T.x>>T.y;
	E.count=0;E.sx=S.x;E.sy=S.y;
	while(!Q.empty())Q.pop();
	Q.push(E);
	
	while(!Q.empty())
	{
		t=Q.front();Q.pop();hash[(t.x*M+t.y)*N*M+t.sx*M+t.sy]=1;
		
		//cout<<t.x<<' '<<t.y<<' '<<t.sx<<' '<<t.sy<<endl;
		
		if(t.count>INF)break;
		if(T.x==t.sx&&T.y==t.sy){ans=t.count;break;}
		if(t.x<N&&Map[t.x+1][t.y])
		{
			temp=t;temp.x++;temp.count++;
			if(t.x+1==t.sx&&t.y==t.sy)temp.sx--;
			if(!hash[(temp.x*M+temp.y)*M*N+temp.sx*M+temp.sy])Q.push(temp);
		}
		if(t.x>1&&Map[t.x-1][t.y])
		{
			temp=t;temp.x--;temp.count++;
			if(t.x-1==t.sx&&t.y==t.sy)temp.sx++;
			if(!hash[(temp.x*M+temp.y)*M*N+temp.sx*M+temp.sy])Q.push(temp);
		}
		if(t.y<M&&Map[t.x][t.y+1])
		{
			temp=t;temp.y++;temp.count++;
			if(t.x==t.sx&&t.y+1==t.sy)temp.sy--;
			if(!hash[(temp.x*M+temp.y)*M*N+temp.sx*M+temp.sy])Q.push(temp);
		}
		if(t.y>1&&Map[t.x][t.y-1])
		{
			temp=t;temp.y--;temp.count++;
			if(t.x==t.sx&&t.y-1==t.sy)temp.sy++;
			if(!hash[(temp.x*M+temp.y)*M*N+temp.sx*M+temp.sy])Q.push(temp);
		}
	}
	if(ans==0)printf("-1\n");
	else printf("%d\n",ans);
}

int main()
{
	int T;
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&N,&M,&T);
	init();
	while(T--)solve();
	return 0;
}
