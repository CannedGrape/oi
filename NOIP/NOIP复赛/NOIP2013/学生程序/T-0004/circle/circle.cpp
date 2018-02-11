#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int n,m,k,x;
long long tim;
long long pf(long long x);
long long ttt(int z,int re);
long long ans;

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&x);
    k=k%n;
    if(k) tim=ttt(k,10)%n;
    ans=(x+(tim*m%n))%n;
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

long long pf(long long x){return x*x;}

long long ttt(int z,int re)
{
    if(z==1) 
    {
             if(re%n) return re%n;
             else return re;
             }
    long long sb=pf(ttt(z/2,re));
    if(z%2==0)
    {
              if(sb%n) return sb%n;
              else return sb;
              }
    else 
    {
         if(sb*re%n) return sb*re%n;
         else return sb*re;
         }
}
