#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <map>
using namespace std;

int f[1007][10007],h[10007];
int highest = 0;
int i,j,N,ans = 0;;


inline void init()
{
       scanf("%d",&N);
       for (i = 1;i <= N;++i)
       {
           for (j = 1;j <= 10000;++j)
           {
               f[i][j] = 0;
               h[j] = 0;
           }
       }

}

inline void work()
{
       int x;
       for (i = 1;i <= N;++i)
       {
           scanf("%d",&x);
           highest = max(highest,x);
           for (j = 1;j <= x;++j)
           {
               f[i][j] = 1;
               if (f[i][j] != f[i-1][j]) h[j]++;
           }
       }
       for (i = 1;i <= highest;++i)
       {
           ans+=h[i];
       }
}

inline void work_2()
{
       int s[100007],hei[100007];
       for (i = 1;i <= N;++i)
       {
           scanf("%d",&hei[i]);
           s[i] = hei[i] - hei[i-1];
           if (s[i] > 0) ans+=s[i];
       }
}

inline void outit()
{
       cout<<ans<<endl;
}

int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    
    init();
    if (N <= 1000) work();
    else work_2();
    outit();
    
//    system("pause");
    fclose(stdin); fclose(stdout);
    return 0;
}
