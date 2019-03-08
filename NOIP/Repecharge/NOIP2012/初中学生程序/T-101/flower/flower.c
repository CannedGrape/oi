#include <stdio.h>

int fe(int i,int j,int use[]) {
	int sum,t;
	if(j==1) return 1;
	if(use[j]==0) return 1;
	sum=0;
	for(t=1;t<=j;t++) {
		if(use[t]>=0) {
			use[t]=use[t]-1;
			sum+=fe(i-1,t,use);
			use[t]++;
		}
	}
	return sum;
}

int main() {
	int f[50][50],use[50],a[50];
	int n,m,
		i,j,
		sum=0;
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++) {
		use[i]=a[i];
	}
	for(i=1;i<=n;i++) {
		use[i]=use[i]-1;
		sum=sum+fe(m,i,use);
		use[i]++;
	}
	printf("%d\n",sum);
	system("PAUSE");
	return 0;
}
