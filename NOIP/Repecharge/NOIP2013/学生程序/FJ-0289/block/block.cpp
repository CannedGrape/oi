#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n,a[100001],f[100001];
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	   scanf("%d",&n);
	   for (int i=1;i<=n;i++) scanf("%d",a+i);
	   a[0]=0;
	memset(f,0,sizeof(f));   
	for (int i=1;i<=n;i++)
	 {
	   if (a[i]<=a[i-1]) f[i]=f[i-1];
	   if (a[i]>a[i-1])  f[i]=f[i-1]+a[i]-a[i-1];
	 }   
	printf("%d",f[n]);
	fclose(stdin);fclose(stdout);
}
