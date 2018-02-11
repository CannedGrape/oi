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
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int n,m,ask;
struct ty
{
	int v,w;
};
vector<ty> a[30001];
bool vis[30001];
int q[100001],tail,head;

void read(int &s)
{
	char c;
	s=0;
	c=getchar();
	while ((c<'0')||(c>'9')) c=getchar();
	while ((c>='0')&&(c<='9')) {s=s*10+c-'0'; c=getchar();}
}

bool search(int &p,int x,int &y)
{
	int i;
	bool flag;
    while (head<=tail)
    {
	  x=q[head];
	  if (head>tail) return false;
	  head++;
	  if (x==y) return true;
	  for (i=0;i<a[x].size();i++)
	    {
		    if (a[x][i].w>=p)
		      {
				  if (!vis[a[x][i].v])
				  {
					q[++tail]=a[x][i].v;
				  }
			  }
	    }
   }
}

bool pd(int &p,int &x,int &y)
{
	memset(q,0,sizeof(q));
	head=1;
	tail=0;
	q[++tail]=x;
    return search(p,x,y);
}

int main()
{
	int i,x,y,maxw=0,minw=1000000,l,r,mid;
	ty tmp;
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
    read(n);
    read(m);
    for (i=1;i<=m;i++)
      {
		 read(x); read(tmp.v); read(tmp.w);
		 if (tmp.w>maxw) maxw=tmp.w;
		 if (tmp.w<minw) minw=tmp.w;
		 a[x].push_back(tmp);
	  }
	read(ask);
	for (i=1;i<=ask;i++)
	  {
		 read(x);
		 read(y);
		 l=minw;
		 r=maxw;
		 if (!pd(l,x,y)) {printf("-1\n"); continue;}
		 if (pd(r,x,y)) {printf("%d",r); continue;}
		 while (l<r-1)
		   {
				mid=(l+r)>>1;
				if (pd(mid,x,y))
				  {
					l=mid;
				  }
				else r=mid-1;
		   }
		printf("%d\n",l);
	  }
	
	return 0;
}
