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

typedef long long LL;
const int MAXN=int(1e5)+3;

LL Ans;
int N,MaxH,LNum,H[MAXN],First[MAXN],Next[MAXN];
bool Vis[MAXN];

int Get() {
	int Num=0,Sign=0;
	char ch;
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar()) if (ch=='-') break;
	ch=='-'?Sign=1:Num=ch-48;
	for (ch=getchar();ch>='0'&&ch<='9';ch=getchar()) Num=Num*10+ch-48;
	return Sign==0?Num:-Num;
}

int main() {
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	N=Get();
	for (int i=1;i<=N;++i) {
		H[i]=Get();
		if (H[i]>MaxH) MaxH=H[i];
	}
	memset(First,-1,sizeof(First));
	for (int i=N;i>=1;--i) {
		Next[i]=First[H[i]];
		First[H[i]]=i;
	}
	Vis[0]=Vis[N+1]=true; LNum=1;
	for (int Hi=0;Hi!=MaxH;++Hi) {
		for (int k=First[Hi];k!=-1;k=Next[k]) {
			if (Vis[k-1]&&Vis[k+1]) --LNum;
			else if ((!Vis[k-1])&&(!Vis[k+1])) ++LNum;
			Vis[k]=true;
		}
		Ans+=LNum;
	}
	cout<<Ans<<endl;
	//system("pause");
	fclose(stdin);fclose(stdout);
	return 0;
}	
