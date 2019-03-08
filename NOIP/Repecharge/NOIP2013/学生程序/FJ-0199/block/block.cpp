#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=100100;
int a[maxn],N,ans=0;
int get(){
    int v=0,f=0; char ch;
    while (!isdigit(ch=getchar())) if (ch=='-') break;
    if (ch=='-') f=1; else v=ch-48;
    while (isdigit(ch=getchar())) v=v*10+ch-48;
    if (f) return -v; else return v;
}

int main(){
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    N=get(); a[0]=0;
    for (int i=1;i<=N;i++){
	    a[i]=get();
	    if (a[i]-a[i-1]>0) ans+=(a[i]-a[i-1]);
	}
	printf("%d\n",ans);
    return 0;
}
