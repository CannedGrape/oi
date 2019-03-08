#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
long n,m,k,x,a[1000005],ans,i;
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&x);
	for(ans=10%n,a[0]=1,i=1;i<=k;++i){
		a[i]=a[i-1]*ans;
		a[i]%=n;
		if(!a[i]||(i>1&&a[i]==a[1]))break;
	}
	a[i]?printf("%d\n",(m*a[k%(i-1)]+x)%n):printf("%d\n",x);
	return 0;
}
