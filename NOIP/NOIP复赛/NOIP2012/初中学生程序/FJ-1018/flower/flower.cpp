#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int a[101],b[101],ans=0,n,m;
void tryy(int l)
{
  int sz,lzw=l,k=0,js;
  for(int i=1;i<=n;i++)
    {
    js=0;
    for(int j=1;j<=l;j++)
      if(i<a[j])
        js++;
    if(js==0&&b[i]!=0)
      {
      sz=a[l];
      a[l]=i;
      b[i]--;
      lzw++;
      for(int j=1;j<=l;j++)
        if(a[j]==0)
          k++;
      if(l-k==m)
        {ans++;
        ans=ans%1000007;}
      else
        tryy(lzw);
      a[l]=sz;
      b[i]++;
     }}
}
int main()
{
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>b[i];
  tryy(1);
  cout<<ans<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}

