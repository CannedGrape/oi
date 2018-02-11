#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cmath>
#include <math.h>
#include <climits>
#include <ctime>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct ty
{
  int a,b;
};
ty s[300001];

void read(int &s)
{
	char c;
	s=0;
	c=getchar();
	while ((c<'0')||(c>'9')) c=getchar();
	while ((c>='0')&&(c<='9')) {s=s*10+c-'0'; c=getchar();}
}

bool cmp(ty a,ty b)
{
	return a.a<b.a;
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,i,j,tmp,ans=0;
	bool flag;
	read(n);
	for (i=1;i<=n;i++) read(s[i].a);
	for (i=1;i<=n;i++) read(s[i].b);
	sort(s+1,s+n+1,cmp);
	for (i=1;i<n;i++)
	  {
		flag=false;
	    for (j=i+1;j<=n;j++)
	      {
			if (s[j-1].b>s[j].b)
			  {
				 tmp=s[j-1].b;
				 s[j-1].b=s[j].b;
				 s[j].b=tmp;
				 ans++;
				 flag=true;
			  }
		  }
		ans=ans%99999997;
		if (!flag) break;
	  }
	printf("%d\n",ans);
	return 0;
}     
		   
