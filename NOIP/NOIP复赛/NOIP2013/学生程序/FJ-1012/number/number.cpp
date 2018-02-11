#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const long long big=-1000000000;
long long n,sum[1000001]={},f[1000001]={},mod,score[1000001],best=big,ans=big,insis[1000001];
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  scanf("%lld%lld",&n,&mod);
  for(long long i=1;i<=n;i++)  scanf("%lld",&sum[i]);
  f[1]=sum[1];
  best=f[1];
  insis[1]=sum[1];
  for(long long i=2;i<=n;i++)
  {
    insis[i]=max(insis[i-1]+sum[i],sum[i]);
    f[i]=max(insis[i],best);
    best=max(best,f[i]);  
  }
  score[1]=f[1]; 
  best=score[1]+f[1];
  for(long long i=2;i<=n;i++)
    score[i]=max(best,score[i-1]+f[i-1]);
  ans=score[1];
  for(long long i=1;i<=n;i++)
    ans=max(ans,score[i]);  
  printf("%lld\n",ans%mod);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
