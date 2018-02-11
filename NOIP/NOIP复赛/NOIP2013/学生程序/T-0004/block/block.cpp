#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int n;
int a[100002];
int sum;
int ans;

bool f;
int l,r,ls,rs;

int find(int st,int en)
{
    for(int i=st+1; i<=en; ++i) if(!a[i]) return i;
}

void del(int l1,int r1)
{
     bool flag=0;
     for(int i=l1+1; i<r1; ++i)
     {
             --a[i];
             --sum;
             if(a[i]) flag=f=1;
             if(!flag)
             { 
                      ls=i;
                      if(!f) l=i;
             }
     }
}

int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int k=0;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
    {
            scanf("%d",&a[i]);
            sum+=a[i];
            if(!a[i] && !k) k=i;
    }
    
    if(!k) k=n+1;
    l=0; 
    r=n+1;
    ls=l;
    rs=k;
    a[l]=0;
    a[r]=0;
    
    while(sum)
    {      
         if(ls!=rs-1)   
         {
                        ++ans;
                        del(ls,rs);
         }
         ls=rs;
         rs=find(rs,r);
         if(ls==rs)
         {
                   for(int i=r-1; i>=l; --i)
                   {
                           if(a[i]>0) break;
                           r=i;
                   }
                   f=0;
                   ls=l;
                   rs=find(ls,r);
         }  
    }
    printf("%d",ans);  
    fclose(stdin);
    fclose(stdout);
    return 0;
}
