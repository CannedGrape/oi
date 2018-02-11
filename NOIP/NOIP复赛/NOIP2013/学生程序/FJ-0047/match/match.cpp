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
const int Mod=99999997;

class Match {
	public :
		int Val,Bh;
		Match():Val(0),Bh(0){}
		bool operator <(const Match &k) const {
			return Val<k.Val;
		}
};
Match A[MAXN],B[MAXN];
int N,Ans,F[MAXN],Pa[MAXN],Pb[MAXN],R[MAXN];

int Lowbit(const int &x) {
	return x&(-x);
}

int Ask_Sum(const int &x) {
	int Sum=0,Px=x;
	while (Px>0) {
		Sum+=F[Px];
		Px-=Lowbit(Px);
	}
	return Sum;
}

void Ins(const int &x) {
	int Px=x;
	while (Px<=N) {
		++F[Px];
		Px+=Lowbit(Px);
	}
	return ;
}	

int Get() {
	int Num=0,Sign=0;
	char ch;
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar()) if (ch=='-') break;
	ch=='-'?Sign=1:Num=ch-48;
	for (ch=getchar();ch>='0'&&ch<='9';ch=getchar()) Num=Num*10+ch-48;
	return Sign==0?Num:-Num;
}

int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	N=Get();
	for (int i=1;i<=N;++i) A[i].Val=Get(),A[i].Bh=i;
	for (int i=1;i<=N;++i) B[i].Val=Get(),B[i].Bh=i;
	sort(A+1,A+N+1); sort(B+1,B+N+1);
	for (int i=1;i<=N;++i) Pa[A[i].Bh]=i;
	for (int i=1;i<=N;++i) Pb[i]=B[i].Bh;
	for (int i=1;i<=N;++i) {
		int Pos=Pa[i];
		R[Pb[Pos]]=i;
	}
	for (int i=N;i>=1;--i) {
		Ans=(Ans+Ask_Sum(R[i]-1))%Mod;
		Ins(R[i]);
	}
	if (Ans<0) Ans+=Mod;
	cout<<Ans<<endl;
	//system("pause");
	fclose(stdin);fclose(stdout);
	return 0;
}	
