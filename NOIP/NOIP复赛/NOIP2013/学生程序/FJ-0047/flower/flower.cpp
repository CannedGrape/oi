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

const int MAXN=int(1e5)+3;
const int MAXT=int(5e5)+3;

class Flower {
	public :
		int Val,Bh;
		Flower():Val(0),Bh(0){}
		bool operator <(const Flower &k) const {
			return Val<k.Val;
		}
};
Flower Lsh[MAXN];
int N,LNum,Ans,H[MAXN],F[4];
int G[4],Max[MAXT][4];

void Insert_Tree(const int &k,const int &l,const int &r,const int &x,const int &y) {
	if (l>y||r<x) return ;
	if (l>=x&&r<=y) {
		for (int i=0;i<=3;++i)
			if (F[i]>Max[k][i]) Max[k][i]=F[i];
		return ;
	}
	int Mid=(l+r)>>1;
	Insert_Tree(k<<1,l,Mid,x,y);
	Insert_Tree(k<<1|1,Mid+1,r,x,y);
	for (int i=0;i<=3;++i) 
		Max[k][i]=max(Max[k<<1][i],Max[k<<1|1][i]);
	return ;
}

void Ask_Max_Tree(const int &k,const int &l,const int &r,const int &x,const int &y) {
	if (l>y||r<x) return ;
	if (l>=x&&r<=y) {
		if (Max[k][2]>G[2]) G[2]=Max[k][2];
		if (Max[k][3]>G[3]) G[3]=Max[k][3];
		return ;
	}
	int Mid=(l+r)>>1;
	Ask_Max_Tree(k<<1,l,Mid,x,y);
	Ask_Max_Tree(k<<1|1,Mid+1,r,x,y);
	return ;
}

void Ask_Min_Tree(const int &k,const int &l,const int &r,const int &x,const int &y) {
	if (l>y||r<x) return ;
	if (l>=x&&r<=y) {
		if (Max[k][0]>G[0]) G[0]=Max[k][0];
		if (Max[k][1]>G[1]) G[1]=Max[k][1];
		return ;
	}
	int Mid=(l+r)>>1;
	Ask_Min_Tree(k<<1,l,Mid,x,y);
	Ask_Min_Tree(k<<1|1,Mid+1,r,x,y);
	return ;
}

int Get() {
	int Sign=0,Num=0;
	char ch;
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar()) if (ch=='-') break;
	ch=='-'?Sign=1:Num=ch-48;
	for (ch=getchar();ch>='0'&&ch<='9';ch=getchar()) Num=Num*10+ch-48;
	return Sign==0?Num:-Num;
}

int main() {
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	N=Get(); memset(Max,-1,sizeof(Max));
	for (int i=1;i<=N;++i) Lsh[i].Val=Get(),Lsh[i].Bh=i;
	sort(Lsh+1,Lsh+N+1); Lsh[0].Val=Lsh[1].Val-1;
	for (int i=1;i<=N;++i) {
		if (Lsh[i].Val!=Lsh[i-1].Val) ++LNum;
		H[Lsh[i].Bh]=LNum;
	}
	for (int i=1;i<=N;++i) {
		G[0]=G[1]=0; G[2]=G[3]=0;
		if (H[i]!=1) Ask_Max_Tree(1,1,LNum,1,H[i]-1);
		if (H[i]!=LNum) Ask_Min_Tree(1,1,LNum,H[i]+1,LNum);
		F[0]=G[2]+1; F[1]=G[3]+1; F[2]=G[0]+1; F[3]=G[1]+1;
		for (int j=0;j<=3;++j)
			if (F[j]>Ans) Ans=F[j];
		Insert_Tree(1,1,LNum,H[i],H[i]);
	}
	printf("%d\n",Ans);
	//system("pause");
	fclose(stdin);fclose(stdout);
	return 0;
}		
