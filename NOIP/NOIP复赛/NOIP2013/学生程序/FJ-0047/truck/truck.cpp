#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

const int MAXN=int(1e4)+3;
const int MAXM=int(1e5)+3;
const int MAXQ=int(3e4)+3;

class Query {
	public :
		int Beg,End,Bh;
		Query():Beg(0),End(0),Bh(0){}
		bool operator <(const Query &k) const {
			return Beg<k.Beg;
		}
};
Query Q[MAXQ];	

int N,M,Qi,A,B,C,Ans[MAXQ],Dis[MAXN];
int Tot,First[MAXN],Next[MAXM],End[MAXM],Val[MAXM];
bool Vis[MAXN];
queue<int> Que;

int Get() {
	int Num=0,Sign=0;
	char ch;
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar()) if (ch=='-') break;
	ch=='-'?Sign=1:Num=ch-48;
	for (ch=getchar();ch>='0'&&ch<='9';ch=getchar()) Num=Num*10+ch-48;
	return Sign==0?Num:-Num;
}

void SetE(const int &x,const int &y,const int &z) {
	Next[++Tot]=First[x]; First[x]=Tot; End[Tot]=y; Val[Tot]=z;
	Next[++Tot]=First[y]; First[y]=Tot; End[Tot]=x; Val[Tot]=z;
	return ;
}

void SPFA(const int &Bd) {
	memset(Dis,-127/3,sizeof(Dis)); 
	Dis[Bd]=-Dis[Bd]; Que.push(Bd);
	while (!Que.empty()) {
		int x=Que.front(); 
		Vis[x]=false; Que.pop();
		for (int k=First[x];k!=0;k=Next[k]) {
			int y=End[k],v=min(Val[k],Dis[x]);
			if (v>Dis[y]) {
				Dis[y]=v;
				if (!Vis[y]) {
					Vis[y]=true;
					Que.push(y);
				}
			}
		}
	}
	return ;
}
	
int main() {
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	N=Get(),M=Get();
	for (int i=1;i<=M;++i) {
		A=Get(),B=Get(),C=Get();
		SetE(A,B,C);
	}
	Qi=Get(); Q[0].Beg=-1; memset(Vis,false,sizeof(Vis));
	for (int i=1;i<=Qi;++i) Q[i].Beg=Get(),Q[i].End=Get(),Q[i].Bh=i;
	sort(Q+1,Q+Qi+1);
	for (int i=1;i<=Qi;++i) {
		if (Q[i].Beg!=Q[i-1].Beg) SPFA(Q[i].Beg);
		Ans[Q[i].Bh]=(Dis[Q[i].End]==Dis[0])?-1:Dis[Q[i].End];
	}
	for (int i=1;i<=Qi;++i) printf("%d\n",Ans[i]);
	//system("pause");
	fclose(stdin);fclose(stdout);
	return 0;
}
