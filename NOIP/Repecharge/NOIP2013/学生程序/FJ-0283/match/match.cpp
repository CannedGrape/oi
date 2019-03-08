#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;
int a[100001],aa[100001],b[100001],bb[100001],cc[100001];
int nn;
long long ans; 
void go1(int x,int y)
{
  int i=x; int j=y;
  int mid=a[(x+y)/2];
  while (i<=j)
    {
      while (a[i]<mid) i++;
      while (a[j]>mid) j--;
       if (i<=j)
        {
		  int w;
		  w=a[i]; a[i]=a[j]; a[j]=w;
		  w=aa[i]; aa[i]=aa[j]; aa[j]=w;
		  i++; j--;
		}
    }
  if (i<y) go1(i,y);
  if (x<j) go1(x,j);		
}
void go2(int x,int y)
{
  int i=x; int j=y;
  int mid=b[(x+y)/2];
  while (i<=j)
    {
      while (b[i]<mid) i++;
      while (b[j]>mid) j--;
       if (i<=j)
        {
		  int w;
		  w=b[i]; b[i]=b[j]; b[j]=w;
		  w=bb[i]; bb[i]=bb[j]; bb[j]=w;
		  i++; j--;
		}
    }
  if (i<y) go1(i,y);
  if (x<j) go1(x,j);		
}

void mmsort(int l,int r)
{
  int ii=l;
  int mid=(l+r)/2+1;
  int jj=(l+r)/2+1;
  int fx[100001]; int t=ii;
  while (ii<=mid&&jj<=r)
   {
    if (cc[ii]<=cc[jj]) {fx[t]=cc[ii]; ii++; t++;}
    else {fx[t]=cc[jj]; ans+=mid-ii; jj++; t++; 	}
    if (ii>=mid) 
    {
	// ans+=jj-mid;
     for (int i=t; i<=r; i++)
      {fx[i]=cc[jj]; jj++;}
	  break;
	}
  if (jj>r)
    {
	  for (int i=t; i<=r; i++)
	  {fx[i]=cc[ii]; ii++;} 
	 break; 	
    }	
   }
  for (int i=l; i<=r; i++)
   cc[i]=fx[i]; 
}
void go(int l,int r)
{
  int mid=(l+r)/2;
  if (l<r)
    {
	  go(l,mid);
	  go(mid+1,r);
	  mmsort(l,r);	
    }
}
int main(){
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  scanf("%d",&nn);
 //  printf("%d",nn);
  for (int i=1; i<=nn; i++)
   {
    scanf("%d",&a[i]);
    aa[i]=i;
   }
   go1(1,nn);
  for (int i=1; i<=nn; i++)
   {
    scanf("%d",&b[i]);
    bb[i]=i;
   }
   go2(1,nn); 
  for (int i=1; i<=nn; i++) 
	cc[aa[i]]=i;    
	ans=0; 
 if (nn<5000)
   {
     for (int i=1; i<=nn-1; i++)
      for (int j=i+1; j<=nn; j++)
       if (cc[i]>=cc[j])
        {
		 ans++;
		 int w;
		 w=cc[i]; cc[i]=cc[j]; cc[j]=w;
		}
	printf("%lld",ans%99999997);	
   }
  else 
   {
    go(1,nn);
    printf("%lld",ans%99999997);
   } 
  fclose(stdin); fclose(stdout);
}

