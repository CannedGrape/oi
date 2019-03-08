# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <algorithm>
# include <math.h>

using namespace std;

int n;
int a[100010],b[100010],f[100010];
int mod = 99999997; 

void openFile() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}

void init() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);		
}

void work() {
	f[0]=0;f[1]=0;
	for (int i=2;i<=n;i++) {
		f[i]=f[i-1];
		for (int j=1;j<=n;j++) {
			if(f[i]!=0) f[i]=min(f[i],f[i]+(a[i]==b[j]));
			else f[i]=f[i]+(a[i]==b[j]);
			f[i]=f[i]%mod;
		}	
	}
	printf("%d\n",f[n]);
}
int main() {
	openFile();
	init();
	work();
	return 0;
}
