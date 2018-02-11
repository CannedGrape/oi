#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,h[100001]={},tot=0,num=0;
bool tll=false;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i,k;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%d",&h[i]);
    h[0]=h[n+1]=-1;
    while (tll==false)
    {
          k=0;
          for (i=1;i<=n;i++)
            {
             if (h[i]==0)
             {num++;h[i]--;}
             if (h[i]>0)
              h[i]--;
             if ((h[i]>=0)&&(h[i-1]==-1))
               k++;
             }
          tot+=k;
          if (num==n) tll=true;
    }
    printf("%d\n",tot);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
