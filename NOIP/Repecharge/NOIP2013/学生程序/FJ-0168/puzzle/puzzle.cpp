#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
int get()
{
	int f=0,v=0;char ch;
	while(!isdigit(ch=getchar()))if(ch=='-')break;
	if(ch=='-')f=1;else v=ch-'0';
	while(isdigit(ch=getchar()))v=v*10+ch-'0';
	if(f==1)return -v;else return v;
}
const int maxn=33,maxl=1000000,maxv=1000003,maxh=1000000;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m,Q,a[maxn][maxn],tot=0;
bool vis[33][33][33][33];
struct pos
{
	int x,y;
	inline pos(){}
	inline pos(int _x,int _y){x=_x,y=_y;}
	inline bool operator ==(const pos &b)const{return x==b.x&&y==b.y;}
	inline bool avl(){return 1<=x&&x<=n&&1<=y&&y<=m&&a[x][y]==1;}
}S,T,E;
struct state
{
	pos p[2];int hash,ans;
	inline void calc()
	{
	//	hash=0;
	//	for(int i=0;i<2;i++)hash=hash*35+p[i].x,hash=hash*35+p[i].y;
	//	hash%=maxv;
	//	if(hash<0)hash+=maxv;
	}
	inline state(){}
	state(pos p0,pos p1){p[0]=p0,p[1]=p1;calc();}
	inline bool operator ==(const state &b)const{return p[0]==b.p[0]&&p[1]==b.p[1];}
}s[maxl+10];

inline bool isanswer(state ss)
{
	if(T==ss.p[1])return 1;else return 0;
}

inline bool Exist(state ss)
{
	return vis[ss.p[0].x][ss.p[0].y][ss.p[1].x][ss.p[1].y];
	//for(int i=Link[ss.hash];i;i=pre[i])
		//if(t[i]==ss)return 1;
//	return 0;
}

inline void add(state ss)
{
	//pre[++tot]=Link[ss.hash]; Link[ss.hash]=tot; t[tot]=ss;
	vis[ss.p[0].x][ss.p[0].y][ss.p[1].x][ss.p[1].y]=1;
}

inline void clear()
{
	//for(int i=1;i<=tot;i++)Link[t[i].hash]=0;tot=0;
	memset(vis,0,sizeof(vis));
}

void bfs()
{
	int front=0,rear=1;
	s[front]=state(E,S);s[front].ans=0;
	add(s[front]);
	while(front!=rear)
	{
		state tp=s[front];
		front++;
		if(front>maxl)front=0;
		for(int i=0;i<4;i++)
		{
			pos e0=tp.p[0],s0=tp.p[1];
			e0.x+=dx[i],e0.y+=dy[i];
			if(!e0.avl())continue;
			if(e0==s0)s0=tp.p[0];
			state next=state(e0,s0);
			if(Exist(next))continue;
			next.ans=tp.ans+1;
			if(isanswer(next))
			{
				printf("%d\n",next.ans);
				clear();
				return;
			}
			s[rear++]=next,add(next);
			if(rear>maxl)rear=0;
		}
	}
	puts("-1");
	clear();
}

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	while(Q--)
	{
		scanf("%d%d%d%d%d%d",&E.x,&E.y,&S.x,&S.y,&T.x,&T.y);
		if(S==T)
		{
			printf("%d\n",0);
			continue;
		}
		bfs();
	}
	//cerr<<sizeof(s)+sizeof(vis)<<endl;
	return 0;
}
