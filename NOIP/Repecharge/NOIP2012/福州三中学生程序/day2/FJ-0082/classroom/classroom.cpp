#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1048576;
int n,m,end;
long long t[10000001];
void build()
{
     int i;
	 long long k;
     for(i=maxn-1;i>=1;i--)
       {k=min(t[i<<1],t[i+i+1]);
        t[i<<1]-=k;
        t[i+i+1]-=k;
        t[i]+=k;
        }
}
void doing(int x,int l,int r)
{
     int ll,rr;
	 long long k;
     for(ll=l-1,rr=r+1;(ll^rr)!=1;ll>>=1,rr>>=1)
       {if(!(ll&1))
          t[ll^1]-=x;
        if(rr&1)
          t[rr^1]-=x;
        k=min(t[ll],t[ll^1]);
        t[ll]-=k;
        t[ll^1]-=k;
        t[ll>>1]+=k;
        k=min(t[rr],t[rr^1]);
        t[rr]-=k;
        t[rr^1]-=k;
        t[rr>>1]+=k;
        }
     while(ll>1)
       {k=min(t[ll],t[ll^1]);
        t[ll]-=k;
        t[ll^1]-=k;
        t[ll>>1]+=k;
        ll>>=1;
        }
}
int main()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    int i,x,l,r;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      scanf("%I64d",&t[maxn+i]);
    build();
    for(i=1;i<=m;i++)
      {scanf("%d%d%d",&x,&l,&r);
       if(!end)
         {doing(x,l+maxn,r+maxn);
          if(t[1]<0)
            end=i;
          }
       }
    
    if(end)
      printf("-1\n%d\n",end);
    else
      printf("0\n");
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
