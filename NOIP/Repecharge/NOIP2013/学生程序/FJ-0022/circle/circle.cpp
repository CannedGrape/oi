#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int N,M,K,X;
long long i,j,k;

inline void init()
{
       scanf("%d%d%d%d",&N,&M,&K,&X);
}

inline void work()
{
       k = M;
       j = K;
       while (j > 0)
       {
             k = 10*k % N;
             j--;
       }
       k = (X+k) % N;
       cout<<k<<endl;
}

inline void work_1()
{
       k = M;
       j = K;
       while (j > 1)
       {
             k = (long long)(100*k % N);
             j-=2;
       }
       if (j == 1) k = (long long)(10 * k % N);
       k = (X+k) % N;
       cout<<k<<endl;
}

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    
    init();
    if (k <= (long long)(1e9)) work();
    else work_1();
//    system("pause");
    fclose(stdin); fclose(stdout);  
    return 0;
}
