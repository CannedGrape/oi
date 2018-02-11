#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a[1000001],b[1000001],c[1000001];
bool d[1000001]={0};
int n,p,k,j,anss=-99999999;
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>n>>p;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  b[1]=a[1];
  c[1]=b[1];
  c[2]=2*c[1];
  for(int i=2;i<=n;i++)
    {
    if(d[i-1]==0)
      {
      if(b[i-1]>(b[i-1]+a[i]))
        {
        b[i]=b[i-1];
        d[i]=1;
        }
        else
          b[i]=b[i-1]+a[i];
      }
    if(d[i-1]==1)
      {
      k=a[i-1]+b[i-1];
      j=k+a[i];
      b[i]=max(k,j);
      b[i]=max(b[i],a[i]);
      if(b[i]==k)
        d[i]=1;
      }
    }
  for(int i=3;i<=n;i++)
    c[i]=max(c[i-1],c[i-1]+b[i-1]);
  for(int j=1;j<=n;j++)
    if(c[j]>anss)
      anss=c[j];
  if(anss>=0)
    anss=anss%p;
    else
      anss=-((-anss)%p);
  cout<<anss<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
