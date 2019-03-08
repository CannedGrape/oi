#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n,a,b,ans;

int main(){
	int i;
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d",&a);
		if (a>b) ans+=a-b;b=a;
	}
	printf("%d\n",ans);
	return 0;
}
