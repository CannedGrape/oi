#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
const int N=1000010;

int n,m,k,flag[N],le,f[N],ans=1;

int main(){int i;
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&f[0]);
	for (le=1;!flag[f[le-1]];le++){
		flag[f[le-1]]=1;
		f[le]=(f[le-1]+m)%n;
	}le--;
	for (i=10;k;k/=2,i=(i*i)%le){
		if (k&1) ans=(ans*i)%le; 
	}
	printf("%d\n",f[ans]);
	return 0;
}
