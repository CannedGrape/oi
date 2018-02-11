#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n,a[100001],f[100001],len=2,ans;
bool che[100001];
bool check(int k)
{
  if (n-k==1) return(true);
  len=0;
  for (int i=1;i<=n;i++) f[i]=0;
  for (int i=1;i<=n;i++) 
   if (!che[i]) f[++len]=a[i];
  bool s=true;
  for (int i=1;i<=len/2;i++)
   if ((f[i*2]>f[i*2-1]&&f[i*2]<f[i*2+1])||f[i*2]<f[i*2-1]&&f[i*2]>f[i*2+1])
   {
		s=false;
		break;
   }
  return(s); 
}
void search(int x,int k){
   if (n-k<ans) return;
   if (check(k))
    {
      if (n-k>ans) ans=n-k;
      return;
    }
   for (int i=x;i<=n;i++)
   if (!che[i])
     {
	   che[i]=true;
	   search(i,k+1);
	   che[i]=false;
	 } 
}
void work()
{
   ans=0;
   for (int i=1;i<=n;i++) che[i]=false;
   search(1,0);
   printf("%d",ans);
   exit(0);
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	  scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	 scanf("%d",a+i);
	if (n<=25) work();
	int i=2;
	int x1,x2,y1,y2,pos=0; 
	while (i<=n)
	 {
	   bool p=false;
	   x1=0;y1=0;x2=0;y2=0;		
	   for (int j=i-1;j>=1;j--)
	    {
	      if (a[i]>a[j]&&!x1) x1=j;
	      if (a[i]<a[j]&&!x2) x2=j;
	      if (x1&&x2) break;
		}
	   for 	(int j=i+1;j<=n;j++)
	    {
	      if (a[i]>a[j]&&!y1) y1=j;
	      if (a[i]<a[j]&&!y2) y2=j;
	      if (y1&&y2) break;
		}
	   if ((x1&&y1)||(x2&&y2))
	    {
			p=true;
		   if (x1&&y1&&x2&&y2)
		    {
			  if (y1<y2) { 
			  pos=y1;f[len-1]=a[x1]; f[len]=a[i];f[++len]=a[y1];
			  }
			  else
			  {
			   pos=y2;f[len-1]=a[x2]; f[len]=a[i];f[++len]=a[y2];
			  }
			}
		   else
		    if (x1&&y1)
		    {
			 pos=y1;f[len-1]=a[x1]; f[len]=a[i];f[++len]=a[y1];	
		    }
		   else 
		    if (x2&&y2)
		    {
			  pos=y2;f[len-1]=a[x2]; f[len]=a[i];f[++len]=a[y2];
			}
		}
		i++;
		if (p) break;
	 }
	while (1)
	 {
	   x1=0;
	   int k=pos;
	   for (int i=k+1;i<=n;i++)
	   {
	   if (a[i]>f[len-1])
	    {
           for (int j=i+1;j<=n;j++)	
		    if (a[j]<a[i])
			 {
			   x1=j;pos=j;
			   break;
			 }	
		  if (k!=pos)
		   f[++len]=a[pos];
		}
	  if (a[i]<f[len-1])
	    {
           for (int j=i+1;j<=n;j++)	
		    if (a[j]>a[i])
			 {
			   x1=j;pos=j;
			   break;
			 }	
		 if (k!=pos)
		   f[++len]=a[pos];
		}
	  }	
	  if (k==pos) break;	
	 }
	 printf("%d",len);
	fclose(stdin);fclose(stdout);
}
