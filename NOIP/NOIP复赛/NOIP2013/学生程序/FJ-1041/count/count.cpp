#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,m,i,j,g,total=0;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        g=i;
        while (g!=0)
        {
        if (g%10==m) total++;
        g/=10;       
        }                 
    }
    printf("%d\n",total);
    fclose(stdin);fclose(stdout);
    return 0;
}
