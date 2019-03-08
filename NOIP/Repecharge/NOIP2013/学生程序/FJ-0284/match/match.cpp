#include<cstdio>
#include<algorithm>
struct p{ int a,b; }t1[100010],t2[100010];
bool cmp(const p&x,const p&y) { return x.a<y.a; }
long long ans=0; 
int n,pei[100010],t[100010],d[100010];
void pai(int l,int r) {
	int m=(l+r)/2;
	if (l+1<r) { pai(l,m); pai(m+1,r); }
	int top1=l,top2=m+1,lon=l-1;
	while (top1<=m&&top2<=r) {
		while (top1<=m&&t[top1]<t[top2]) d[++lon]=t[top1++];
		ans=(ans+top2-top1) % 99999997 ; d[++lon]=t[top2++];
	}
	while (top1<=m) d[++lon]=t[top1++];
	while (top2<=r) d[++lon]=t[top2++];
	for (int i=l; i<=r; i++) t[i]=d[i];
}
int main(){
	freopen("match.in" ,"r",stdin );
	freopen("match.out","w",stdout);
	scanf("%d\n",&n);
	for (int i=1; i<=n; i++) scanf("%d",&t1[i].a);
	for (int i=1; i<=n; i++) scanf("%d",&t2[i].a);
	for (int i=1; i<=n; i++) t1[i].b = t2[i].b=i ;
	std::sort(t1+1,t1+n,cmp); 
	std::sort(t2+1,t2+n,cmp);
	for (int i=1; i<=n; i++) t[t1[i].b]=t2[i].b;
	pai(1,n);                printf("%lld",ans);
	fclose(stdin);           fclose(stdout);
}
