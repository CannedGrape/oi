#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
const int N=30,M=100000;
int n,m,q;
int beg[N][N];
typedef int State[N][N];
State st[M];
int dis[M];

int hash(int s)
{
	int v=0;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++){
		v=(v+(i*m+j)*st[s][i][j])%M;
	}
	return v;
}

int head[M],next[M];

int insert(int s)
{
	int h=hash(s);
	int u=head[h];
	while(u!=-1){
		if(memcmp(st[u],st[s],sizeof(st[s]))==0)
		    return 0;
		u=next[u];
	}
	next[s]=head[h];
	head[h]=s;
	return 1;
}

const int E=1<<3,S=1<<4;
const int dx[]={-1,1,0,0},
          dy[]={0,0,-1,1};

void work(int TX,int TY)
{
	memset(head,-1,sizeof(head));
	int front=0,rear=1;
	int ans=0;
	while(front<rear){
		State& s=st[front];
		int EX,EY,SX,SY;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		    if(s[i][j]==E) EX=i,EY=j;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		    if(s[i][j]==S) SX=i,SY=j;
		if(SX==TX&&SY==TY)
		    {ans=dis[front];break;}
		
		for(int d=0;d<4;d++){
			State& t=st[rear];
			memcpy(t,s,sizeof(s));
			int X=EX+dx[d],Y=EY+dy[d];
			if(t[X][Y]!=0){
				t[EX][EY]=s[X][Y];
				t[X][Y]=s[EX][EY];
				dis[rear]=dis[front]+1;
				if(insert(rear)) rear++;
			}
		}
		front++;
	}
	if(front==rear) cout<<"-1"<<endl;
	else cout<<ans<<endl;
	
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	
	cin>>n>>m>>q;
	memset(beg,0,sizeof(beg));
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
	    cin>>beg[i][j];
	for(int i=0;i<q;i++){
		int EX,EY,SX,SY,TX,TY;
		cin>>EX>>EY>>SX>>SY>>TX>>TY;
		EX--,EY--,SX--,SY--,TX--,TY--;
		dis[0]=0;
		memcpy(st[0],beg,sizeof(beg));
		st[0][EX][EY]=E;
		st[0][SX][SY]=S;
		work(TX,TY);
	}
	return 0;
}
