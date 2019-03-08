#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
long f[10005][10005],n,m,x,y,z,i,j,k;
int main(){
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)f[i][j]=-1;
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		f[x][y]=max(f[x][y],z);
		f[y][x]=max(f[y][x],z);
	}
	for(k=1;k<=n;++k)
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				if(i!=j)f[i][j]=max(f[i][j],min(f[i][k],f[k][j]));
	scanf("%d",&n);
	for(;n;--n){
		scanf("%d%d",&x,&y);
		printf("%d\n",f[x][y]);
	}
	return 0;
}
				
