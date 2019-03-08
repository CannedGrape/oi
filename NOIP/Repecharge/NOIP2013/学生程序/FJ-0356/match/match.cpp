#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100007;
const int mod=99999997;
int n,i,ans,now;
int A[maxn],B[maxn],L[maxn],posA[maxn],posB[maxn];
int C[maxn];
struct Point {
	int v,id;
	bool operator<(const Point &X)const{
	  return v<X.v;	
	}
}a[maxn];
void add(int x,int value){
	for(int i=x;i<=n;i+=i&-i)C[i]+=value;
}
int sum(int x){
	int tmp=0;
	for(int i=x;i>0;i-=i&-i)tmp+=C[i];
	return tmp;
}
int abs(int a){
	return a>0?a:(-a);
}
int main(){
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  cin>>n;
  for(i=1;i<=n;i++)scanf("%d",&A[i]);
  for(i=1;i<=n;i++)scanf("%d",&B[i]);
  for(i=1;i<=n;i++){a[i].v=A[i];a[i].id=i;}
  sort(a+1,a+n+1);
  for(i=1;i<=n;i++)posA[a[i].id]=i;
  for(i=1;i<=n;i++){a[i].v=B[i];a[i].id=i;}
  sort(a+1,a+n+1);
  for(i=1;i<=n;i++)L[i]=a[i].id;
  for(i=1;i<=n;i++)posB[a[i].id]=i;
  for(i=n;i>=1;i--){
		now=L[posA[i]]+sum(L[posA[i]]);
		ans=(ans+abs(i-now))%mod;
		add(L[posA[i]],-1); 
  }
  cout<<ans;
  fclose(stdin);
  fclose(stdout);
  return 0;
}

