#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;
#define MOD 99999997;

struct MATCH{int place,value;} a[100007],b[100007];
int N;
int i,j,k,ans = 0;
long long f[1007] = {};

bool cmp(MATCH A,MATCH B)
{
     return (A.value < B.value);
}

inline void init()
{
       scanf("%d",&N);
       for (i = 1;i <= N;++i)
       {
           scanf("%d",&a[i].value);
           a[i].place = i;
       }
       for (i = 1;i <= N;++i)
       {
           scanf("%d",&b[i].value);
           b[i].place = i;
       }
       
       sort(a+1,a+N+1,cmp);
       sort(b+1,b+N+1,cmp);
}

inline void work()
{
       for (i = 1;i <= N;++i)
       {
           if (a[i].place > b[i].place)
           {
                          for (j = b[i].place;j <= a[i].place-1;++j)
                          {
                              f[j]++;
                          }
           }
           if (b[i].place > a[i].place)
           {
                          for (j = a[i].place;j <= b[i].place-1;++j)
                          {
                              f[j]++;
                          }
           }
       }
       for (i = 1;i <= N;++i)
       {
           if (f[i] > 0) ans = (ans + 1) % MOD;
       }
       cout<<ans<<endl;
}

int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    
    init();
    work();
    
    fclose(stdin); fclose(stdout);
//    system("pause");
    return 0;
}
