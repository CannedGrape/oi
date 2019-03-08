#include<cstdio>
int n,h[100010],ans=0,hig,low=1;
int main(){
	freopen("block.in" ,"r",stdin );
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&h[i]);
	while (low<n) {
		hig =low; while (h[hig+1]>=h[hig]&&hig<n) hig++;
		low =hig; while (h[low+1]<=h[low]&&low<n) low++;
		ans+=h[hig]-h[low];
	}   ans+=h[low];
	printf("%d",ans);
} 
