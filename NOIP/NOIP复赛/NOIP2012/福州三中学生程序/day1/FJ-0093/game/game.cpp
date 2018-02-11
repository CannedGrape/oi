#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int n,a[1010],b[1010];
long long money[1010],cj[1010];
long long newcj[1010],newmax;
long long maxmo;
int maxwe,jh;
int main()
{
   freopen("game.in","r",stdin);
   freopen("game.out","w",stdout);	
	scanf("%d",&n);
	scanf("%d%d",&a[0],&b[0]);
	for(int i=1;i<=n;i++)
	  {
		scanf("%d%d",&a[i],&b[i]);
	  }
	cj[0]=a[0];
	for(int i=1;i<n;i++)
	   cj[i]=cj[i-1]*a[i];
    for(int i=1;i<=n;i++)
	  money[i]=cj[i-1]/b[i];
	bool flag=true;
	while(flag==true)
	   {
		 flag=false;
		  maxmo=0;
		  maxwe=0;
		 for(int i=1;i<=n;i++)
		   if(maxmo<money[i])
		   {
			   maxmo=money[i];maxwe=i;
			}
		 jh=0;
		 for(int i=1;i<maxwe;i++)
		   {
			 newcj[i]=cj[i-1]*a[maxwe];
			 for(int j=i+1;j<maxwe;j++)
			   {newcj[j]=newcj[j-1]*a[j];}
			 newmax=newcj[i-1]/b[maxwe];
			 for(int j=i+1;j<maxwe;j++)
				if(newmax>=maxmo)
				  break;
			    else
				  if(newcj[j-1]/b[j]>newmax)
					 newmax=newcj[j-1]/b[j];
			 if(newmax<newcj[maxwe-1]/b[i])
				 newmax=newcj[maxwe-1]/b[i];
	         if(newmax<maxmo&&newmax!=0)
			   {
				  jh=i;maxmo=newmax;flag=true;
				}
			}
		 if(flag==true)
		   {swap(a[maxwe],a[jh]);
			 swap(b[maxwe],b[jh]);
			 for(int j=jh+1;j<maxwe;j++)
			   {cj[j]=cj[j-1]*a[j];}
			 for(int j=jh;j<=maxwe;j++)
				money[j]=cj[j-1]/b[j];
			}
		}
   printf("%lld\n",maxmo);
   fclose(stdin);
   fclose(stdout);
  return 0;	
}