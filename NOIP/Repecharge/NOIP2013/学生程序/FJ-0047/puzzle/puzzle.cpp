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

const int MAXN=int(3e1)+1;
const int MAXF=int(1e9)+3;

int Dx[4]={0,1,0,-1};
int Dy[4]={-1,0,1,0};
int N,M,Q,O,Ans,Kx,Ky,Bx,By,Ex,Ey;
bool Vis[MAXN][MAXN],Mve[MAXN][MAXN],Tar[MAXN][MAXN];

int Get() {
	int Sign=0,Num=0;
	char ch;
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar()) if (ch=='-') break;
	ch=='-'?Sign=1:Num=ch-48;
	for (ch=getchar();ch>='0'&&ch<='9';ch=getchar()) Num=Num*10+ch-48;
	return Sign==0?Num:-Num;
}

void Dfs(const int &Nx,const int &Ny,const int &Step) {
	if (Step>=Ans) return ;
	if (Tar[Ex][Ey]) {
		Ans=Step;
		return ;
	}
	for (int i=0;i<=3;++i) {
		int Mx=Nx+Dx[i],My=Ny+Dy[i];
		if (Mx>=1&&Mx<=N&&My>=1&&My<=M&&Vis[Mx][My]&&Mve[Mx][My]) {
			Mve[Nx][Ny]=false;
			Tar[Nx][Ny]=Tar[Mx][My];
			Dfs(Mx,My,Step+1);
			Mve[Nx][Ny]=true;
			Tar[Nx][Ny]=false;
		}
	}
	return ;
}

int main() {
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	N=Get(),M=Get(),Q=Get();
	for (int i=1;i<=N;++i)
		for (int j=1;j<=M;++j) {
			O=Get();
			(O==0)?Vis[i][j]=false:Vis[i][j]=true;
		}
	memset(Mve,true,sizeof(Mve));
	memset(Tar,false,sizeof(Tar));
	for (int Qi=1;Qi<=Q;++Qi) {
		Kx=Get(),Ky=Get(),Bx=Get(),By=Get(),Ex=Get(),Ey=Get();
		Tar[Bx][By]=true; Ans=MAXF; Dfs(Kx,Ky,0);
		Tar[Bx][By]=false; if (Ans==MAXF) Ans=-1;
		printf("%d\n",Ans);
	}
	//system("pause");
	fclose(stdin);fclose(stdout);
	return 0;
}
