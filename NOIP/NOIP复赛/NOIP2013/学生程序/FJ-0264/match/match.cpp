#include <cstdio>
#include <algorithm>
const int N=100001,mo=99999997;
int v[N],n,ans,tree[N*4],a[N],b[N],savea[N],saveb[N],sp[N];
int finda(int t){
	int l=0,r=n,mid;
	while (l+1<r){
		mid=(l+r)/2;
		if (savea[mid]<t) l=mid;
		else r=mid;
	}
	return r;
}
int findb(int t){
	int l=0,r=n,mid;
	while (l+1<r){
		mid=(l+r)/2;
		if (saveb[mid]<t) l=mid;
		else r=mid;
	}
	return r;
}
void makev(){
	for (int i=1;i<=n;i++) sp[finda(a[i])]=i;
	for (int i=1;i<=n;i++) v[i]=sp[findb(b[i])];
}
int getnum(int l,int r,int rt,int x,int y){
	if (x<=l && r<=y) return tree[rt];
	int mid=(l+r)/2,res=0;
	if (x<=mid) res+=getnum(l,mid,rt*2,x,y);
	if (mid<y) res+=getnum(mid+1,r,rt*2+1,x,y);
	return res;
}
void add(int l,int r,int rt,int x){
	++tree[rt];
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) add(l,mid,rt*2,x);
	else add(mid+1,r,rt*2+1,x);
}
int getans(){
	int res=0;
	for (int i=1;i<=n;i++){
		res=(res+getnum(1,n,1,v[i],n))%mo;
		add(1,n,1,v[i]);
	}
	return res;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		savea[i]=a[i];
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		saveb[i]=b[i];
	}
	std::sort(savea+1,savea+n+1);
	std::sort(saveb+1,saveb+n+1);
	makev();
	printf("%d",getans());
	fclose(stdin);
	fclose(stdout);
}
