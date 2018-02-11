#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
int n;
inline void findd()
{
    for(int i=n/2+1;i>=2;--i)
        if(n%i == 0){
            printf("%d\n",i);
            return;
        }
}
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    scanf("%d",&n);
    findd();
    fclose(stdin);
    fclose(stdout);
//    system("pause");
    return 0;
}
