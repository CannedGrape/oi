#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cctype>
#include <ctime>
#include <cmath>
#include <math.h>

using namespace std;

int h[100001],a[100001][6];

void read(int &s)
{
	char c;
	s=0;
	c=getchar();
	while ((c<'0')||(c>'9')) c=getchar();
	while ((c>='0')&&(c<='9')) {s=s*10+c-'0'; c=getchar();}
}

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
    int n,i,j,ans;
    read(n);
    h[0]=10000000;
    a[0][0]=a[0][1]=a[0][2]=a[0][3]=0;
    a[1][0]=a[1][1]=a[1][2]=a[1][3]=1;
    for (i=1;i<=n;i++) 
	  {
	   read(h[i]);
	   for (j=1;j<i;j++)
	     {
			if (h[j]>h[i])
			  {
				if (a[j][1]+1>a[i][0]) a[i][0]=a[j][1]+1;
				if (a[j][2]+1>a[i][3]) a[i][3]=a[j][2]+1;
			  }
			else if (h[j]<h[i])
			  {
				if (a[j][0]+1>a[i][1]) a[i][1]=a[j][0]+1;
				if (a[j][3]+1>a[i][2]) a[i][2]=a[j][3]+1;
			  }
		 }
	  }
	ans=a[n][0];
	if (a[n][1]>ans) ans=a[n][1];
	if (a[n][2]>ans) ans=a[n][2];
	if (a[n][3]>ans) ans=a[n][3];
	printf("%d\n",ans);
	return 0;
} 
