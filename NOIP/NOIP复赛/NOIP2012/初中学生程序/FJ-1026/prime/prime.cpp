#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<string.h>
#include<cmath>
#include<stdlib.h>
using namespace std;
int n;
void work()
{
     for(int i=2;i<=n;++i)
       if(n%i==0) {printf("%d\n",n/i);return ;}
}
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    scanf("%d",&n);
    work();
    fclose(stdin);
    fclose(stdout);

return 0;
}
