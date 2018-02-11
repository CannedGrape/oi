#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN=100005,INF=9999999;
int n;
int h[MAXN]; 
int ans;
int f1[MAXN][2],f2[MAXN][2];
int Get()
{ 
  char ch; int sum=0; bool f=false;
  while (!isdigit(ch=getchar()))
    if (ch=='-') f=true;sum=ch-48;
  while (isdigit(ch=getchar())) sum=sum*10+ch-48;
  if (f) return -sum;else return sum;
}
void init()
{ 
  n=Get();
  for (int i=1;i<=n;i++) h[i]=Get();
}
void solve()
{  
  f1[1][1]=1; f1[1][0]=-INF; 
  for (int i=2;i<=n;i++)
    { 
	  int _max1=-INF,_max2=0;
      for (int j=i-1;j>=1;j--)
		{ 
          if (h[i]>h[j] && f1[j][1]>_max1) _max1=f1[j][1];
          if (h[i]<h[j] && f1[j][0]>_max2) _max2=f1[j][0];
		}
		f1[i][0]=_max1+1; f1[i][1]=_max2+1;
	}

  f2[1][1]=1; f2[1][0]=-INF; 
  for (int i=2;i<=n;i++)
    { 
	  int _max1=-INF,_max2=0;
      for (int j=i-1;j>=1;j--)
		{ 
          if (h[i]<h[j] && f2[j][1]>_max1) _max1=f2[j][1];
          if (h[i]>h[j] && f2[j][0]>_max2) _max2=f2[j][0];
		}
		f2[i][0]=_max1+1; f2[i][1]=_max2+1;
	}
	
  for (int i=1;i<=n;i++) ans=max(ans,max(f1[i][0],max(f1[i][1],max(f2[i][0],f2[i][1])))); 
  printf("%d\n",ans);   
}
int main()
{  
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  init();
  solve();
  return 0;
}
