#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <deque>

using namespace std;

const int MAXN=10010,INF=100000000;

struct query{
  int a,b,num,ans;
}Q[30010];
struct node{
  int num,weight,next;
}al[MAXN],room[100010];

int pos=1,N,M,dist[MAXN];
bool inqueue[MAXN];

bool cmp1(query,query);
bool cmp2(query,query);
void addedge(int,int,int);
void SPFA(int);

int main(){
  freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
  cin >> N >> M;
  int a,b,t;
  for (int i=1;i<=M;++i){
    scanf("%d%d%d",&a,&b,&t);
    addedge(a,b,t); addedge(b,a,t);
  }
  int T; cin >> T;
  for (int i=1;i<=T;++i){
    scanf("%d%d",&Q[i].a,&Q[i].b);
    Q[i].num=i;
    if (Q[i].a>Q[i].b){
      int t=Q[i].a; Q[i].a=Q[i].b; Q[i].b=t;
    }
  }
  sort(Q+1,Q+1+T,cmp1);
  for (int i=1;i<=T;++i){
    if (i==1 || Q[i].a!=Q[i-1].a) SPFA(Q[i].a);
    Q[i].ans=dist[Q[i].b];
  }
  sort(Q+1,Q+1+T,cmp2);
  for (int i=1;i<=T;++i) printf("%d\n",Q[i].ans);
  return 0;
}

bool cmp1(query q1,query q2){return q1.a<q2.a;}
bool cmp2(query q1,query q2){return q1.num<q2.num;}

void addedge(int u,int v,int w){
  int p=pos++; room[p].num=v; room[p].weight=w;
  room[p].next=al[u].next; al[u].next=p;
}

void SPFA(int s){
  for (int i=1;i<=N;++i){
    dist[i]=-1;
    inqueue[i]=false;
  }
  dist[s]=INF;
  inqueue[s]=true;
  deque <int> q;
  q.push_back(s);
  int u,v,w;
  while (!q.empty()){
    u=q.front(); q.pop_front();
    for (int p=al[u].next;p;p=room[p].next){
      v=room[p].num; w=room[p].weight;
      if (min(dist[u],w)>dist[v]){
	dist[v]=min(dist[u],w);
	if (!inqueue[v]){
	  inqueue[v]=true;
	  if (q.empty()) q.push_back(v);
	  else{
	    if (dist[v]>dist[q.front()]) q.push_front(v);
	    else q.push_back(v);
	  }
	}
      }
    }
    inqueue[u]=false;
  }
}
