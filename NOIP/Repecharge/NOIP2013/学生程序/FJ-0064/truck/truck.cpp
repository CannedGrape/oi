#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
int n,m,q,x,y,z;
int ans=0;bool zg[10001]={};
int map[10001][10001]={};bool ctl[10001]={};
void fs(int r,int anss,int dqc)
{if (r<=m)
    {int as=anss;
     for (int i=1;i<=n;i++)
        {if (!zg[i])
            {zg[i]=true;
             if (anss>map[dqc][i])
                {anss=map[dqc][i];
                }
             if (i==y)
                {if (ans<anss)
                    {ans=anss;
                    }
                }
             else
                {fs(r+1,anss,i);
                }
             zg[i]=false;anss=as;
            }
        }
    }
}
int main()
{freopen("truck.in","r",stdin);
 freopen("truck.out","w",stdout);
 scanf("%d %d",&n,&m);
 for (int i=1;i<=m;i++)
    {scanf("%d %d %d",&x,&y,&z);
     ctl[x]=true;ctl[y]=true;
     if (map[x][y]<z)
        {map[x][y]=z;map[y][x]=z;
        }
    }
 scanf("%d",&q);
 for (int i=1;i<=q;i++)
    {scanf("%d %d",&x,&y);
     if (ctl[x]&&ctl[y])
        {zg[x]=true;
         fs(1,100099,x);
         if (ans!=0)
            {printf("%d\n",ans);
            }
         else
            {printf("-1\n");
            }
         ans=0;
        }
     else
        {printf("-1\n");
        }
    }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
