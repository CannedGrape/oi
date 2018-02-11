#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
int n,m,ans;
long long r[1000001],d[1000001];
int s[1000001],t[1000001];
long long f[1000001];
void qsort(int l,int r)
{
    int i,j,mid;
    mid=s[(l+r)/2];
    i=l;
    j=r;
    while(i<=j)
    {
      while(s[i]<mid) i++;
      while(s[j]>mid) j--;
      if(i<=j)
      {
        swap(s[i],s[j]);
        swap(t[i],t[j]);
        swap(d[i],d[j]);
        i++;j--;
      }
   }
   if(i<r) qsort(i,r);
   if(l<j) qsort(l,j);
}

void init()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      scanf("%lld",&r[i]);
    for(j=1;j<=m;j++)
      scanf("%lld%d%d",&d[j],&s[j],&t[j]);
    qsort(1,m);
}

bool dp()
{
    int i,j;
    for(j=1;j<=n;j++)
      f[j]=r[j];
    ans=0;
    for(i=1;i<=m;i++)
     for(j=t[i];j>=s[i];j--)
     {
       if(f[j]<d[i]) {ans=i;return false;}
       else 
         f[j]=f[j]-d[i];
     }
    return true;
}
                   
int main()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    init();
    if(dp()) printf("0\n");
    else 
    {
      printf("-1\n");
      printf("%d\n",ans);
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
