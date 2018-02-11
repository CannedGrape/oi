#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;
const int N=100001;
int n,a[N],save[N],tree[2][N*4],f[2][N],ans=1,num;
void makesave(){
	sort(save+1,save+n+1);
	save[0]=1;
	for (int i=2;i<=n;i++)
	if (save[i]!=save[i-1]) save[++save[0]]=save[i];
	num=save[0];
}
int find(int t){
	int l=0,r=save[0],mid;
	while (l+1<r){
		mid=(l+r)/2;
		if (save[mid]<t) l=mid;
		else r=mid;
	}
	return r;
}
void makea(){
	for (int i=1;i<=n;i++) a[i]=find(a[i]);
}
void add(int t,int l,int r,int rt,int x,int y){
	if (tree[t][rt]<y) tree[t][rt]=y;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) add(t,l,mid,rt*2,x,y);
	else add(t,mid+1,r,rt*2+1,x,y);
}
int max(int x,int y){ return x>y ? x : y; }
int getmax(int t,int l,int r,int rt,int x,int y){
	if (x>y) return -1;
	if (x<=l && r<=y) return tree[t][rt];
	int mid=(l+r)/2,res=-1;
	if (x<=mid) res=max(res,getmax(t,l,mid,rt*2,x,y));
	if (mid<y) res=max(res,getmax(t,mid+1,r,rt*2+1,x,y));
	return res;
}
void worka(){
	f[1][1]=1;
	add(1,1,num,1,a[1],f[1][1]);
	for (int i=2;i<=n;i++){
		int x=getmax(0,1,num,1,a[i]+1,num);
		if (x==-1) x=0;
		f[1][i]=x+1;
		x=getmax(1,1,num,1,1,a[i]-1);
		if (x!=-1) f[0][i]=x+1;
		add(1,1,num,1,a[i],f[1][i]);
		add(0,1,num,1,a[i],f[0][i]);
		if (ans<f[0][i]) ans=f[0][i];
		if (ans<f[1][i]) ans=f[1][i];
	}
}
void workb(){
	f[1][1]=1;
	add(1,1,num,1,a[1],f[1][1]);
	for (int i=2;i<=n;i++){
		int x=getmax(0,1,num,1,1,a[i]-1);
		if (x==-1) x=0;
		f[1][i]=x+1;
		x=getmax(1,1,num,1,a[i]+1,num);
		if (x!=-1) f[0][i]=x+1;
		add(1,1,num,1,a[i],f[1][i]);
		add(0,1,num,1,a[i],f[0][i]);
		if (ans<f[0][i]) ans=f[0][i];
		if (ans<f[1][i]) ans=f[1][i];
	}
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		save[i]=a[i];
	}
	makesave();
	makea();
	memset(tree,-1,sizeof(tree));
	memset(f,-1,sizeof(f));
	worka();
	//for (int i=1;i<=n;i++) printf("%d %d\n",f[0][i],f[1][i]);
	memset(tree,-1,sizeof(tree));
	memset(f,-1,sizeof(f));
	workb();
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
}
