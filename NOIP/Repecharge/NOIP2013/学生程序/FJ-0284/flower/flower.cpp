#include<cstdio>
int n,t=2,h[100010],low=1,hig,ans=0;
int main(){
	freopen("flower.in" ,"r",stdin );
	freopen("flower.out","w",stdout);
	scanf("%d%d",&n,&h[1]);
	for (int i=2; i<=n; i++) {
		scanf("%d",&h[t]);
		if (h[t]!=h[t-1]) t++; 
	}   t--;  if (t==1) ans=1;
	while (low<t) {
		hig=low; while (h[hig+1]>=h[hig]&&hig<t) hig++;
		low=hig; while (h[low+1]<=h[low]&&low<t) low++;
		ans+=2 ;
	}   
	if (hig==low ) ans--;
	if (h[1]<h[2]) ans++;
	printf("%d",ans);
} 
