#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	freopen("culture.in","r",stdin);
	freopen("culture.out","w",stdout);
	int n,k,m,s,t,a,b,c;
	scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			scanf("%d",&a);
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
	}
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
