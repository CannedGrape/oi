#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<algorithm>
#define key 99999997
struct P{
	int p,v;
}a[200000],b[200000];
int sum[200000],c[200000],ans,n;
bool cmp(const P&X,const P&Y){
	if(X.v==Y.v) return X.p<Y.p;
	return X.v<Y.v; 
}
int lowbit(int x){
	return x&(-x);
}
int cal(int x){
	int temp=0;
	while(x>0){
		temp=(temp+sum[x])%key;
		x-=lowbit(x);
	}
	return temp;
}
void update(int x){
	while(x<=n){
		sum[x]++;
		x+=lowbit(x);
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  {
		scanf("%d",&a[i].v);
		a[i].p=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i].v);
		b[i].p=i;
	}
	std::sort(a+1,a+1+n,cmp);
	std::sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++) c[b[i].p]=a[i].p;
	for(int i=n;i;i--){
		ans=(ans+cal(c[i]-1))%key;
		update(c[i]);
	}
	printf("%d",ans);
	return 0;
}

