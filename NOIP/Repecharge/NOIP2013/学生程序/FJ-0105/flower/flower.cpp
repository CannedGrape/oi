#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int n,i,minn=100001;
int h[100001];
bool u[100001];

bool pd()
{
    int k,p=1;
    int a[4];
    for(k=1;k<=n;k++)
    {
        if((u[k]==true)&&(p<=3))
        {
            a[p]=h[k];
            p++;
        }
        if((u[k]==true)&&(p==4))
        {
            if(a[1]>=a[2]||a[2]<=a[3])
              return false;
        }
    }
    return true;  
}

void tryy(int t)
{
    int j;
    if(pd()==true&&t-1<minn)
      minn=t-1;
    else
    {
        for(j=1;j<=n;j++)
        {
            if(u[j]==true)
            {
                u[j]=false;
                tryy(t+1);
                u[j]=true;
            }
        }
    }
    
}

int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&h[i]);
    h[0]=-1;
    for(i=1;i<=n;i++)
      u[i]=true;
    tryy(1);
    if(n-minn>minn)  
      printf("%d\n",n-minn);
    else
      printf("%d\n",minn);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
