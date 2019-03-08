#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
int n,m,ans=0,num[10000][100];
bool l[10000][100];
void t(int i,int s)
{ ans+=num[i][s];
  ans=ans%20123;
  if(i<n-1)
  { int count=num[i][s];
    int j=s-1;
    while(count>0)
    { j++;
      if(j==m)
       j=0;
      while(l[i][j]==0)
      { j++;
        if(j==m)
         j=0;
      }
      count--;
    }
    t(i+1,j);
  }
}
int main()
{ freopen("treasure.in","r",stdin);
  freopen("treasure.out","w",stdout);
  cin>>n>>m;
  short i,j,s;
  for(i=0;i<n;i++)
   for(j=0;j<m;j++)
   { cin>>l[i][j];
     cin>>num[i][j];
   }
  cin>>s;
  t(0,s);
  cout<<ans<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
