#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
long mx[100005][19],mi[100005][19],g[19],i,j,ans1,ans2,last,n;
int rmqmin(int l,int r){
	int m=log2(r-l+1);
	return min(mi[l][m],mi[r-g[m]+1][m]);
}
int rmqmax(int l,int r){
	int m=log2(r-l+1);
	return max(mx[l][m],mx[r-g[m]+1][m]);
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&mx[i][0]);
		mi[i][0]=mx[i][0];
	}
	for(i=0;i<19;++i)g[i]=1<<i;
	for(i=1;g[i]<=n;++i)
		for(j=1;j+g[i]-1<=n;++j){
			mx[j][i]=max(mx[j][i-1],mx[j+g[i-1]][i-1]);
			mi[j][i]=min(mi[j][i-1],mi[j+g[i-1]][i-1]);
		};
	for(mx[0][0]=last=ans1=0,i=1;i<=n;++i){
		if(i-last>1){
			long tmp=rmqmax(last+1,i-1);
			if(tmp>mx[last][0]&&tmp>mx[i][0]){
				ans1+=2;
				last=i;
			};
		}
		else if(mx[i][0]<mx[last][0])last=i;
	}
	for(i=last+1;i<=n;++i)
		if(mx[i][0]>mx[last][0]){
			++ans1;
			break;
		};
	for(mx[0][0]=~0U>>1,ans2=last=0,i=1;i<=n;++i){
		if(i-last>1){
			long tmp=rmqmin(last+1,i-1);
			if(tmp<mi[last][0]&&tmp<mi[i][0]){
				ans2+=2;
				last=i;
			};
		}
		else if(mx[i][0]>mx[last][0])last=i;
	}
	for(i=last+1;i<=n;++i)
		if(mx[i][0]<mx[last][0]){
			++ans2;
			break;
		};
	printf("%d\n",ans1>ans2?ans1:ans2);
	return 0;
}
