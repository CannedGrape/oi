#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

short int h[100001];
int n,i,step=0;

bool allzero()
{
    int j;
    for(j=1;j<=n;j++)
      if(h[j]!=0)
        return false;
    return true;
}

void dec()
{
    int k;
    for(k=1;k<=n;k++)
      if(h[k]>0)
        h[k]--;
}

int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&n);
    h[0]=0;
    for(i=1;i<=n;i++)
      scanf("%d",&h[i]);
    while(allzero()==false)
    {
        for(i=1;i<=n;i++)
          if(h[i]!=0&&h[i-1]==0)
            step++;
        dec();
    }
    printf("%d\n",step);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
