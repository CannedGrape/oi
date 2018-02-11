#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
struct pii{long sum,pos;}mi[100005][19];
long g[25],i,n,ans,j;
pii min(pii a,pii b){
	return a.sum<b.sum?a:b;
}
pii rmqmin(int x,int y){
	long m=log2(y-x+1);
	return min(mi[x][m],mi[y-g[m]+1][m]);
}
void dfs(int l,int r,int num){
	if(l==r){
		ans+=mi[l][0].sum-num;
		return;
	}
	pii tmp=rmqmin(l,r);
	ans+=tmp.sum-num;
	if(tmp.pos>l)dfs(l,tmp.pos-1,tmp.sum);
	if(tmp.pos<r)dfs(tmp.pos+1,r,tmp.sum);
}
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&mi[i][0].sum);
		mi[i][0].pos=i;
	}
	for(ans=i=0;i<19;++i)g[i]=1<<i;
	for(i=1;g[i]<=n;++i)
		for(j=1;j+g[i]-1<=n;++j)mi[j][i]=min(mi[j][i-1],mi[j+g[i-1]][i-1]);
	dfs(1,n,0);
	printf("%d\n",ans);
	return 0;
}
		
	
