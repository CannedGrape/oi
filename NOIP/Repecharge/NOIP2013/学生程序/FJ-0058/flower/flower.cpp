#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define P 101000

using namespace std;

int n,a[P];
int f[P][2],g[P][2],ans = 1,head1,tail1,head2,tail2,pos1[P],pos2[P];

int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i = 1;i <= n;i++) scanf("%d",&a[i]);
    if(n <= 1000)
    {
    for(i = 1;i <= n;i++) {f[i][0] = f[i][1] = 1;g[i][0] = g[i][1] = i;}
    for(i = 2;i <= n;i++)
    {
          for(j = 1;j <= i - 1;j++)
          {
                if(f[i][0] < f[j][0])
                {
                           f[i][0] = f[j][0];g[i][0] = g[j][0];
                }
                if(f[i][1] < f[j][1])
                {
                           f[i][1] = f[j][1];g[i][1] = g[j][1];
                }
                if(((f[j][0] % 2 == 0) && (a[g[j][0]] > a[i])) || ((f[j][0] % 2 != 0) && (a[g[j][0]] < a[i])))
                {
                           if(f[i][0] < f[j][0] + 1)
                           {
                                      f[i][0] = f[j][0] + 1;
                                      g[i][0] = i;
                           }
                }
                if(((f[j][1] % 2 == 0) && (a[g[j][1]] < a[i])) || ((f[j][1] % 2 != 0) && (a[g[j][1]] > a[i])))
                {
                           if(f[i][1] < f[j][1] + 1)
                           {
                                      f[i][1] = f[j][1] + 1;
                                      g[i][1] = i;
                           }
                }
          }
          ans = max(ans,f[i][0]);
          ans = max(ans,f[i][1]);
    }
    printf("%d\n",ans);
    }
    else
    {
        for(i = 1;i <= n;i++) {f[i][0] = f[i][1] = 1;g[i][0] = g[i][1] = i;}
        head1 = tail1 = head2 = tail2 = 1;pos1[1] = pos2[1] = 1;
        for(i = 2;i <= n;i++)
         {
                j = pos1[tail1];
                if(f[i][0] < f[j][0])
                {
                           f[i][0] = f[j][0];g[i][0] = g[j][0];
                }
                if(((f[j][0] % 2 == 0) && (a[g[j][0]] > a[i])) || ((f[j][0] % 2 != 0) && (a[g[j][0]] < a[i])))
                {
                           if(f[i][0] < f[j][0] + 1)
                           {
                                      f[i][0] = f[j][0] + 1;
                                      g[i][0] = i;
                           }
                }
                j = pos1[tail1 - 1];
                if(f[i][0] < f[j][0])
                {
                           f[i][0] = f[j][0];g[i][0] = g[j][0];
                }
                if(((f[j][0] % 2 == 0) && (a[g[j][0]] > a[i])) || ((f[j][0] % 2 != 0) && (a[g[j][0]] < a[i])))
                {
                           if(f[i][0] < f[j][0] + 1)
                           {
                                      f[i][0] = f[j][0] + 1;
                                      g[i][0] = i;
                           }
                }
                if(f[pos1[tail1]][0] < f[i][0]) 
                {
                  ++tail1;pos1[tail1] = i;
                }
                j = pos2[tail2];               
                if(f[i][1] < f[j][1])
                {
                           f[i][1] = f[j][1];g[i][1] = g[j][1];
                }
                if(((f[j][1] % 2 == 0) && (a[g[j][1]] < a[i])) || ((f[j][1] % 2 != 0) && (a[g[j][1]] > a[i])))
                {
                           if(f[i][1] < f[j][1] + 1)
                           {
                                      f[i][1] = f[j][1] + 1;
                                      g[i][1] = i;
                           }
                }
                j = pos2[tail2 - 1];               
                if(f[i][1] < f[j][1])
                {
                           f[i][1] = f[j][1];g[i][1] = g[j][1];
                }
                if(((f[j][1] % 2 == 0) && (a[g[j][1]] < a[i])) || ((f[j][1] % 2 != 0) && (a[g[j][1]] > a[i])))
                {
                           if(f[i][1] < f[j][1] + 1)
                           {
                                      f[i][1] = f[j][1] + 1;
                                      g[i][1] = i;
                           }
                }
                if(f[pos2[tail2]][1] < f[i][1]) 
                {
                  ++tail2;pos2[tail2] = i;
                }
          ans = max(ans,f[i][0]);
          ans = max(ans,f[i][1]);
            }
          printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
