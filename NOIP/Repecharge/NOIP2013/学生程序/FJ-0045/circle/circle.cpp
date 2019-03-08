#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m,k,x,t;
int a[1000001];
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&x);
    a[0]=x;
    for(int i=1;i<=n-1;i++)
       a[i]=(x+m*i)%n;
    printf("%d\n",x);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
