#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n,ans;
int a[100005]={},b[100005]={},to[100005]={};
int aa[100005]={},bb[100005]={},c[100005]={};
void input()
{
     scanf("%d",&n);
     for(int i=1;i<=n;++i)
       {scanf("%d",&aa[i]);
        a[i]=i;}
     for(int i=1;i<=n;++i)
       {scanf("%d",&bb[i]);
        b[i]=i;}
}
bool cmpa(int x,int y)
{
     if( aa[x]<aa[y] ) return true;
     else return false;
}
bool cmpb(int x,int y)
{
     if( bb[x]<bb[y] ) return true;
     else return false;
}
void gb(int l,int r)
{
     int i,j,mid,p,k;
     if(l!=r)
       {
        mid=(l+r)/2;
        gb(l,mid);
        gb(mid+1,r);
        i=l;j=mid+1;
        k=l;
        while( i<=mid && j<=r )
          {if( to[i]<to[j] ) { c[k]=to[i];++k;++i; }
           else 
             {c[k]=to[j];
              ans=(ans+mid-i+1)%99999997;
              ++k;++j; 
              }
          }
        if( i<=mid)
          for(int p=i;p<=mid;++p)
            {c[k]=to[p];
             ++k;
            }
        if( j<=r)
          for(int p=j;p<=r;++p)
            {c[k]=to[p];
             ++k;
            }
        for(int p=l;p<=r;++p)
          to[p]=c[p];
       }
}
void work()
{
     int p;
     sort(a+1,a+n+1,cmpa);
     sort(b+1,b+n+1,cmpb);
     for(int i=1;i<=n;++i)
       {p=b[i];
        to[p]=a[i];
       }
     ans=0;
     gb(1,n);
     printf("%d\n",ans);
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    input();
    work();
    fclose(stdin);
    fclose(stdout);
return 0;
}
