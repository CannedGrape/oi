#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
short n,m,a[100],remain,remain2[100];
int ans=0;
void f(short s)
{ if(s==n-1)
  { if(remain<=a[s])
    { ans++;
      if(ans>=1000007)
       ans-=1000007;
    }
  }
  else
  { short i;
    for(i=0;i<=a[s];i++)
     if(remain>=i&&remain<=remain2[s])
     { remain-=i;
       f(s+1);
       remain+=i;
     }
  }
}
int main()
{ freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  cin>>n>>m;
  remain=m;
  int i,j;
  for(i=0;i<n;i++)
   cin>>a[i];
  for(i=0;i<n;i++)
   for(j=i;j<n;j++)
    remain2[i]+=a[j];
  f(0);
  cout<<ans<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
