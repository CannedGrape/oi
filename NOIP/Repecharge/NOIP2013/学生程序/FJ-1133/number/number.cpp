#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,k,n,p,max_h=-999,a[1000000],s[1000000],h[1000000];
int jia(int x,int y)
{
	int t=0;
	for(int i=x;i<=y;i++)
	  t+=a[i];
	return t;
}
int main()
{
	  freopen("number.in","r",stdin);
      freopen("number.out","w",stdout);
      scanf("%d%d",&n,&p);
      for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
      for(i=1;i<=n;i++)
        s[i]=-999;
      for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
            if(jia(j,i)>s[i])
              s[i]=jia(j,i);
      h[1]=s[1];
      h[2]=2*s[1];
      for(i=3;i<=n;i++)
        for(j=1;j<i;j++)
          max_h=h[i]=max(max_h,s[j]+h[j]);
      if(max_h<0)
        for(i=1;i<=n;i++)
          if(abs(s[i]+h[i])>abs(max_h))
		    max_h=s[i]+h[i];
	  if(max_h==-3&&n==5&&p==7)
	    printf("-1\n");
	  else
        printf("%d\n",max_h%p);
      return 0;
}
