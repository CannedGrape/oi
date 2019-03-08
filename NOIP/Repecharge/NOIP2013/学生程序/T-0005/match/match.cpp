#include <iostream>
#define FOR(i,a,b) for(int i = a;i <= b;++i)
using namespace std;

int n;
long long k;
long long t;
int fh1[100001];
int fh2[100001];

long long int CalcOnce()
{
    long long k = 0,st;
    FOR(i,1,n)
    {
        st = fh1[i] - fh2[i];
        k += st * st;
    }
    return k;
}

template <typename t> t PF(t a){return a * a;}

void BaoSou()
{
     bool none = false;
     t = 0;
     while (!none)
     {
         none = true;
         //change 1
         FOR(i,1,n - 1)
         {
             long long s = PF((long long)(fh1[i] - fh2[i])) + PF((long long)(fh1[i + 1] - fh2[i + 1])) - PF((long long)(fh1[i] - fh2[i + 1])) - PF((long long)(fh1[i + 1] - fh2[i]));
             if (s > 0)
             {
                 ++t;
                 k -= s;
                 s = fh1[i];
                 fh1[i] = fh1[i + 1];
                 fh1[i + 1] = s;
                 none = false;
             }
             t = t % 99999997;
         }
     }
     return;
}

int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&fh1[i]);
    FOR(i,1,n) scanf("%d",&fh2[i]);
    k = CalcOnce();
    BaoSou();
    printf("%lld",t);
    //scanf("%*");
    fclose(stdin);fclose(stdout);
    return 0;
}
