#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define maxn 100010
#define lowbit(i) i&-i
using namespace std;
int a[maxn],b[maxn],c[maxn],d[maxn],n,ans=0;
int start,end;
int find (int x,int s[]){
   int l=0,r=n-1,mid;
   while (l<=r){
	   mid=(l+r)/2;
	   if (s[mid]>x) r=mid-1;
	   if (s[mid]<x) l=mid+1;
	   if (s[mid]==x) return mid;
   }
   return mid;
}
void add(int x){
	c[x]+=1;
	while (x<=n+10){
		x=x+lowbit(x);
		c[x]+=1;
	}
}
int sum(int x){
	int tmp=0;tmp=tmp+c[x];
	while (x>0){
	    x=x-lowbit(x);
	    tmp=(tmp+c[x])%99999997;
	}
	return tmp;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);c[i]=a[i];
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);d[i]=b[i];
	}
	sort(c+1,c+n+1);
	sort(d+1,d+n+1);
	for (int i=1;i<=n;i++) {
		int q=find(a[i],c);
		a[i]=q;
	}
	for (int i=1;i<=n;i++){
		int q=find(b[i],d);
		b[i]=q;
	}int i;
	for (i=1;i<=n;i++){
		if (a[i]!=b[i]) break; 
	}
	start=i;
	for (i=0;i<=n+10;i++) c[i]=0;
	for (i=n;i>=1;i--) if (a[i]!=b[i]) break; 
	end=i;int ans=0;
	for (int i=start;i<=end;i++){
		add(a[i]);
		ans=(ans+i-sum(a[i]))%99999997;
	}
    cout<<ans<<endl;
	return 0;
}
