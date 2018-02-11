#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int x[10001][100],n,m,p,k[10001][100],y=0,z;
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m-1;j++){
			scanf("%d%d",&k[i][j],&x[i][j]);
		}
	}
	scanf("%d",&p);
	for(int i=1;i<=n;i++){
		y+=x[i][p];
		z=x[i][p];
		while(z>0){
			if(p==m-1){
				p=-1;
			}
			if(k[i][p+1]==1){
				z--;
			}
			p++;
		}
	}
	printf("%d",y%20123);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
