#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
int sum[4000010][2];
int n,h,S,L,R,v;
void Max(int &x,int y){
	if(y>x) x=y;
}
int query(int root,int l,int r){
	if(L<=l&&r<=R)
		return sum[root][S];
	int t=0,mid=(l+r)>>1;
	if(L<=mid) Max(t,query(root<<1  ,    l,mid));
	if(R >mid) Max(t,query(root<<1|1,mid+1,  r));
	return t;
}
void update(int root,int l,int r){
	Max(sum[root][S],v);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(h<=mid) update(root<<1,l,mid);
	else update(root<<1|1,mid+1,r);
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
		scanf("%d",&h);
		int t1,t2;
		S=0,L=0,R=h-1;
		if(L<=R)
			t1=query(1,0,1000000)+1;
		else t1=1;
		S=1,L=h+1,R=1000000;	
        if(L<=R)
			t2=query(1,0,1000000)+1;
        else t2=1;
        
		S=1; v=t1;
		update(1,0,1000000);
		S=0; v=t2;
        update(1,0,1000000);
	}
	printf("%d",std::max(sum[1][0],sum[1][1]));
	return 0;
}

