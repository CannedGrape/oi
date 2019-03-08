#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000100;
int n,m,k,x,a[maxn],ans[maxn],g[maxn][3];
int gcd(int a,int b){
    if (b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&x);
    for (int i=0;i<n;i++){
	    g[i][0]=(i+m)%n; 
		ans[i]=i; 
    }
    int cnt=n/gcd(n,m);
    int w=1,tmp=10;
    for (;k;k>>=1){
	    if (k&1)w=w*tmp%cnt;
	    tmp=tmp*tmp%cnt;
	}
    tmp=0;
    for (;w;w>>=1){
	    if (w%2==1) for (int i=0;i<n;i++) ans[i]=g[ans[i]][tmp];
	    for (int i=0;i<n;i++) g[i][tmp^1]=g[g[i][tmp]][tmp];
	    tmp^=1;
	}
	printf("%d\n",ans[x]);
	return 0;
}
