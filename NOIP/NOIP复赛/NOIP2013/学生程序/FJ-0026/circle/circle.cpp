#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<ctime>
#include<cstring>
#define N int(5e06+10)
#define mod int(1e08)
using namespace std;
long long a[N];
void chu(long long &x)
{
     memset(a,0,sizeof(a));
                       while(x>=8)
                       {
                                  ++a[0];
                                  x-=8;
                                  }
                       if(x==0)a[++a[0]]=1;
                       else
                       {
                           a[++a[0]]=1;
                           for(int i=x;i>=1;i--)
                           a[a[0]]*=10;
                           }
                       return;
     }
long long qumo(const long long &y)
{
     long long tem=0;
                     for(int i=a[0];i>=1;i--)
                     {   
                             tem=(a[i]+tem*mod)%y;
                             }
                     return tem;
     }
long long gcd(long long a,long long b)
{
    if(a%b==0) return b;
    else return (b,a%b);
    }
int main()
{
    freopen("circle.in","r",stdin);freopen("circle.out","w",stdout);
    long long n,m,k,x;
    cin>>n>>m>>k>>x;
    long long tem=gcd(n,m);
    long long lcm=n*m/tem;
    chu(k);
    long long z=qumo(lcm);
    if(z>=mod)
    a[0]=1;
    else a[0]=2;
    for(long long i=1;i<=a[0];i++)
    {
            a[i]=z%mod;
            z/=mod;
            }
    tem=0;
    for(long long i=1;i<=a[0];i++)
    {
            a[i]=a[i]*m+tem;
            tem=a[i]/mod;
            a[i]%=mod;
            }
    if(tem!=0)
    a[++a[0]]=tem;
    z=qumo(n);
    z+=x;
    cout<<z%n;
    fclose(stdin);fclose(stdout);
    return 0;
    }
