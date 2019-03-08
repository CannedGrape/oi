#include <cstdio>
const int N=100001;
int n,a[N],ans;
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
}
