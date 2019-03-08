#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100007;
int s[maxn],a[maxn];
int i,n,now,ans;
int main(){
  freopen("block.in","r",stdin);
  freopen("block.out","w",stdout);
  cin>>n;
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  for(i=1;i<=n;i++)s[i]=a[i]-a[i-1];
  for(i=1;i<=n;i++){
		if(s[i]<0)ans-=s[i];
		now+=s[i];
  }
  ans+=now;
  cout<<ans;
  fclose(stdin);
  fclose(stdout);
  return 0;
}

