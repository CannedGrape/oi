#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=101000;
const int rod=99999997;

int n; LL ans;

struct Seq
{
       int x,y;
       Seq(){};
       Seq(int a,int b) {x=a; y=b;}
       bool operator <(const Seq &rhs)const
       {
            return x>rhs.x;
       }
}A[maxn],B[maxn];

void init()
{
     int x;
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
     {
         scanf("%d",&x);
         A[i]=Seq(x,i);
     }
     for(int i=1;i<=n;i++)
     {
         scanf("%d",&x);
         B[i]=Seq(x,i);
    }
}

void work()
{
     ans=0;
     sort(A+1,A+n+1); sort(B+1,B+n+1);
     for(int i=1;i<=n;i++) ans+=abs(A[i].y-B[i].y);
     ans=(ans/2)%rod;
     cout<<ans<<endl;
}

int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    init();
    work();
    return 0;
}

