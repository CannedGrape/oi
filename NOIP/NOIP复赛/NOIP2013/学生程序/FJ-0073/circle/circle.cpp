#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
int k,m,n,x;
int a[100000001];
int main()
{
 freopen("circle.in","r",stdin);
 freopen("circle.out","w",stdout);
 scanf("%d%d%d%d",&n,&m,&k,&x);
 int i=k;
 if(i%10==0)
	    {for(int j=1;j<=i/10;j++)
		    {a[j]=100%n;}
		  i=i/10;  
		}
	 else
	   {if(i==1)
		    a[1]=10;
		 else
		 {for(int j=1;j<=i/10;j++)
		     {a[j]=100%n;}
		   a[i/10+1]=(10*(i%10))%n;
		  i=i/10+1;
		 }
		}
 while(i!=1)
    {if(i%2==0)
	    {for(int j=1;j<=i/2;j++)
		    {a[j]=(a[j]+a[j+i/2])%n;}
		  i=i/2;  
		}
	 else
	   {for(int j=1;j<=i/2;j++)
		    {a[j]=(a[j]+a[1+j+i/2])%n;}
		  i=i/2+1; 
		} 
	}
 printf("%d\n",(x+a[1]%n*m)%n);
 return 0;
}
