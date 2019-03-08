#include<iostream>
#include<fstream>
#include<string.h>
#include<queue>
using namespace std;
const int N=10000+2000,M=50000+10000,Z=100000;
int n,m,q;
int u[M*2],v[M*2],w[M*2];

int head[N],next[M*2];

const int INF=Z*100;
typedef pair<int,int> pii;

int work(int S,int T)
{
	bool vis[N];
	memset(vis,0,sizeof(vis));
	int d[N];
	for(int i=1;i<=n;i++) d[i]=-INF;
	d[S]=INF;
	priority_queue<pii,vector<pii>,less<pii> > q;
	q.push(make_pair(d[S],S));
	while(!q.empty()){
		pii U=q.top(); q.pop();
		int x=U.second;
		if(d[x]!=U.first) continue;
		
		for(int e=head[x];e!=-1;e=next[e]){
			int weight=min(d[x],w[e]);
			int V=v[e];
			if(weight>d[V]){
				d[V]=weight;
				if(!vis[V]){
					vis[V]=1;
				    q.push(make_pair(d[V],V));
			    }
				
				
			}
		}
			
			
	}
	int ans=-1;
	if(d[T]!=-INF) ans=d[T];
	return ans;
}

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	
	memset(head,-1,sizeof(head));
	
	cin>>n>>m;
	for(int e=0;e<m;e++){
		int U,V,W;
		cin>>U>>V>>W;
		
		u[e]=U,v[e]=V,w[e]=W;
		next[e]=head[U];
		head[U]=e;
		
		u[e+m]=V,v[e+m]=U,w[e+m]=W;
		next[e+m]=head[V];
		head[V]=e+m;
	}
	
	cin>>q;
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		cout<<work(x,y)<<endl;
		
	}
	return 0;
}
