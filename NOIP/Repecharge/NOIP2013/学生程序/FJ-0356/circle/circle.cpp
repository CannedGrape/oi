#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL n,m,k,x,ans,mod;
LL power(LL a,LL n){
	if(!n)return 1;
	if(n==1)return a;
	LL tmp=power(a,n/2);
	if(n&1)return (tmp*tmp*a)%mod; else return (tmp*tmp)%mod;
}
int main(){
  freopen("circle.in","r",stdin);
  freopen("circle.out","w",stdout);
  cin>>n>>m>>k>>x;
  mod=n;
  ans=(m*(power((LL)10,k))%mod+x)%mod;
  cout<<ans;
  fclose(stdin);
  fclose(stdout);
  return 0;
}

