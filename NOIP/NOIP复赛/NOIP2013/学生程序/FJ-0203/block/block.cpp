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

int h[150001],ans=0,cur,n;

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
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int i,maxh=0;
	bool flag;
	read(n);
	for (i=1;i<=n;i++) {read(h[i]); if (h[i]>maxh) maxh=h[i];}
	for (cur=1;cur<=maxh;cur++)
	  {
		 flag=false;
		 for (i=1;i<=n;)
		   {
			  if (h[i]<cur) 
			    {
				  if (flag) ans++;
				  while (h[i]<cur) i++;
			    }
			    else 
				  {
					 i++;
					 flag=true;
				  }
		   }
		  if (h[n]>=cur) ans++;
	  }
	printf("%d\n",ans);
	return 0;
} 
