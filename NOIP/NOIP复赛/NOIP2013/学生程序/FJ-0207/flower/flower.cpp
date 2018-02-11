#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n,ans;
int a[100005];
int f[100005];
int pd(int x,int y,int z)
{	if (x==0)
	 return 1;
	if (z%2==0)
	{if (a[x]<a[y])
	  return 0;
	 if (a[x]>a[y])
	  return 1;
	}
	if (z%2==1)
	{if (a[x]>a[y])
	  return 0;
	 if (a[x]<a[y])
	  return 1;
	}
	return 0;
}
int pd1(int x,int y,int z)
{	if (x==0)
	 return 1;
	if (z%2==0)
	{if (a[x]<a[y])
	  return 1;
	 if (a[x]>a[y])
	  return 0;
	}
	if (z%2==1)
	{if (a[x]>a[y])
	  return 1;
	 if (a[x]<a[y])
	  return 0;
	}
	return 0;
}
int main()
{	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int i,j,temp;
	scanf ("%d",&n);
	for (i=1;i<=n;i++)
	 scanf ("%d",&a[i]);
	if (n<=1000)
	{for (i=1;i<=n;i++)
	 {temp=-2147000005;
	  for (j=1;j<=i;j++)
	  {if (pd(i-j,i,f[i-j]))
	    temp=max(temp,f[i-j]+1);
	  }
	  f[i]=temp;
	 }
	 temp=f[1];
	 for (i=1;i<=n;i++)
	  temp=max(temp,f[i]);
	 ans=temp;
	 //for (i=1;i<=n;i++) cout<<f[i]<<' ';cout<<endl;
	 for (i=1;i<=n;i++)
	 {temp=-2147000005;
	  for (j=1;j<=i;j++)
	  {if (pd1(i-j,i,f[i-j]))
	    temp=max(temp,f[i-j]+1);
	  }
	  f[i]=temp;
	 }
	 temp=f[1];
	 for (i=1;i<=n;i++)
	  temp=max(temp,f[i]);
	 ans=max(ans,temp);
	 printf ("%d\n",ans);
	}
	else
	{int minn,maxx;
	 temp=1;
	 minn=a[1];
	 maxx=-2100000000;
	 for (i=2;i<=n;i++)
	 {if (temp%2==1)
	  {if (a[i]>minn)
	    maxx=a[i],temp++;
	   else
	    minn=min(minn,a[i]);
	  }
	  else
	  {if (a[i]<maxx)
	    minn=a[i],temp++;
	   else
	    maxx=max(maxx,a[i]);
	  }
	 }
	 ans=temp;
	 temp=1;
	 maxx=a[1];
	 minn=2100000000;
	 for (i=2;i<=n;i++)
	 {if (temp%2==0)
	  {if (a[i]>minn)
	    maxx=a[i],temp++;
	   else
	    minn=min(minn,a[i]);
	  }
	  else
	  {if (a[i]<maxx)
	    minn=a[i],temp++;
	   else
	    maxx=max(maxx,a[i]);
	  }
	 }
	 ans=max(temp,ans);
	 printf ("%d\n",ans);
	}
	return 0;
} 
