#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=1200000;
const int maxn=100010;
int i,n,ql,qr,ans;
int f[maxn][2],h[maxn];
int maxv0[INF*10],maxv1[INF*10];
int max(int a,int b){
	return a>b?a:b;
}
void add0(int o,int l,int r,int pos,int key){
	int lc=o*2,rc=o*2+1,mid=(r-l)/2+l;
	maxv0[o]=max(maxv0[o],key);
	if(l==r)return;
	if(pos<=mid)add0(lc,l,mid,pos,key);
	if(mid<pos)add0(rc,mid+1,r,pos,key);
}
void add1(int o,int l,int r,int pos,int key){
	int lc=o*2,rc=o*2+1,mid=(r-l)/2+l;
	maxv1[o]=max(maxv1[o],key);
	if(l==r)return;
	if(pos<=mid)add1(lc,l,mid,pos,key);
	if(mid<pos)add1(rc,mid+1,r,pos,key);
}
int query0(int o,int l,int r){
	int lc=o*2,rc=o*2+1,mid=(r-l)/2+l,ans=0;
	if(ql>qr)return 0;
	if(ql<=l&&r<=qr)return maxv0[o];
	if(ql<=mid)ans=max(ans,query0(lc,l,mid));
	if(mid<qr)ans=max(ans,query0(rc,mid+1,r));
	return ans;
}
int query1(int o,int l,int r){
	int lc=o*2,rc=o*2+1,mid=(r-l)/2+l,ans=0;
	if(ql>qr)return 0;
	if(ql<=l&&r<=qr)return maxv1[o];
	if(ql<=mid)ans=max(ans,query1(lc,l,mid));
	if(mid<qr)ans=max(ans,query1(rc,mid+1,r));
	return ans;
}
int main(){
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  cin>>n;
  for(i=1;i<=n;i++)scanf("%d",&h[i]);
  for(i=1;i<=n;i++){
		ql=h[i]+1; qr=INF; f[i][0]=query1(1,0,INF)+1;
		ql=0; qr=h[i]-1; f[i][1]=query0(1,0,INF)+1;
		add0(1,0,INF,h[i],f[i][0]);
		add1(1,0,INF,h[i],f[i][1]);
  }
  ans=max(f[n][0],f[n][1]);
  cout<<ans;
  fclose(stdin);
  fclose(stdout);
  return 0;
}

