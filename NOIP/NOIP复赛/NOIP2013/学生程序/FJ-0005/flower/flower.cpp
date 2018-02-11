#include<cstdio>
#include<cstring>
#include<algorithm>
#define MaxN 100000

int tf[2][MaxN+5];
int tmodify(int o,int x,int d){
	for(++x;x<MaxN+5;x+=x&-x)
		tf[o][x]=std::max(d,tf[o][x]);
}

int tquery(int o,int x){
	int res=-1;
	for(;x;x-=x&-x) res=std::max(tf[o][x],res);
	return res;
}

int m,y[MaxN+5];
int hash_find(int x){
	int res;
	for(int l=0,r=m-1,mid;l<=r;) y[mid=l+r>>1]<=x?l=(res=mid)+1:r=mid-1;
	return res;
}

int n,ans,h[MaxN+5];
int main(){
	freopen("flower.in","r",stdin),freopen("flower.out","w",stdout);
	scanf("%d",&n),y[0]=h[0]=-1;
	for(int i=1;i<=n;++i) scanf("%d",&h[i]),y[i]=h[i];
	std::sort(y,y+n+1),m=std::unique(y,y+n+1)-y;
	for(int i=0;i<=n;++i) h[i]=hash_find(h[i]);
	memset(tf,-1,sizeof(tf)),tmodify(0,h[0],0);
	for(int i=1,t;i<=n;++i){
		if (~(t=tquery(1,MaxN-h[i]))) tmodify(0,h[i],t+1);
		if (~(t=tquery(0,h[i]))) tmodify(1,MaxN-h[i],t+1);
	}
	ans=std::max(tquery(0,MaxN+1),tquery(1,MaxN+1));	
	memset(tf,-1,sizeof(tf)),tmodify(0,h[0],0);
	for(int i=1,t;i<=n;++i){
		if (~(t=tquery(1,h[i]))) tmodify(0,MaxN-h[i],t+1);
		if (~(t=tquery(0,MaxN-h[i]))) tmodify(1,h[i],t+1);
	}
	printf("%d\n",std::max(std::max(tquery(0,MaxN+1),tquery(1,MaxN+1)),ans));
	return 0;
}
