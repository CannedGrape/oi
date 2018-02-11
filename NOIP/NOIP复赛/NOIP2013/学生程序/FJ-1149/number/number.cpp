#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,p,ans;
int shu[1000100],tz[1000100],fs[1000100],zc;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,maxi=0,tmp=0,k;
	cin>>n>>p;
	shu[0]=0;
	for (i=1;i<=n;i++)
	{ scanf("%d",&shu[i]);
	}
	//sort(a+1,a+1+n,cmp);//以小朋友手上数字大小来排序的下标 
	tz[1]=shu[1];fs[1]=shu[1];
	/*//deal-tz
	for (i=2;i<=n;i++)
	{ if (shu[i-1]>0 && shu[i]>0) tz[i]=tz[i-1]+shu[i];
	  else
	  { if (shu[i-1]>0) tz[i]=tz[i-1];
	    else tz[i]=shu[i];
	  }
	}
	maxi=tz[1]+fs[1];
	for (i=2;i<=n;i++)
	{ fs[i]=maxi;
	  if (fs[i]+tz[i]>maxi) maxi=fs[i]+tz[i];
	}*/
	//deal-tz
	maxi=shu[1];
	for (i=2;i<=n;i++)
	{ if (shu[i]<0) tz[i]=tz[i-1];
	  else
	  {for (j=1;j<=i;j++)
	   { tmp=0;
	   	 for (k=j;k<=i;k++)
	     { tmp+=shu[k];
	       if (tmp>maxi) maxi=tmp;
		 }
	   }
	   tz[i]=maxi;
	 }
	}
	//deal-fs
	maxi=tz[1]+fs[1];
	for (i=2;i<=n;i++)
	{ fs[i]=maxi;
	  zc=fs[i]+tz[i];
	  if (zc>maxi) maxi=zc;
    }
	//for (i=1;i<=n;i++) cout<<tz[i]<<' '<<fs[i]<<endl;
	maxi=-2147483641;
	for (i=1;i<=n;i++)
	{ if (fs[i]>maxi) maxi=fs[i];
	}
	if (maxi<0)
	{ maxi=abs(maxi);
	  ans=maxi%p*(-1);
	}
	else ans=maxi%p;
	cout<<ans<<endl;
	return 0;
}
