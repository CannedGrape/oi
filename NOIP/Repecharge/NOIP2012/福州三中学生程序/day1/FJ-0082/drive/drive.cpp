#include<iostream>
#include<cstdio>
using namespace std;
long long h[100001],s;
int n,m;
long long zzz(long long z)
{
	if(z>0)
	  return z;
    else
	  return -z;
}
int main()
{
    freopen("drive.in","r",stdin);
    freopen("drive.out","w",stdout);
    
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%I64d",&h[i]);
    scanf("%I64d",&s);
    long long ka,kb,dis[3],lasth[3];
    int now,next[3],who,where=1;
    double why=-1.0;
    for(i=1;i<=n;i++)
      {ka=0,kb=0,now=i,who=0;
       while(1)
         {if(who)
            {next[1]=0;
             lasth[1]=10000000000ll;
             dis[1]=10000000000ll;
             for(j=now+1;j<=n;j++)
               {if(zzz(h[j]-h[now])<dis[1]||(zzz(h[j]-h[now])==dis[1]&&h[j]<lasth[1]))
                  {dis[1]=zzz(h[j]-h[now]);
                   next[1]=j;
                   lasth[1]=h[j];
                   }
                }
             if(next[1]==0)
               break;
             if(ka+kb+dis[1]>s)
               break;
             kb+=dis[1];
             now=next[1];
             }
          else
            {next[1]=next[2]=0;
             lasth[1]=lasth[2]=10000000000ll;
             dis[1]=dis[2]=10000000000ll;
             for(j=now+1;j<=n;j++)
               {if(zzz(h[j]-h[now])<dis[1]||(zzz(h[j]-h[now])==dis[1]&&h[j]<lasth[1]))
                  {dis[2]=dis[1];
                   next[2]=next[1];
                   lasth[2]=lasth[1];
                   dis[1]=zzz(h[j]-h[now]);
                   next[1]=j;
                   lasth[1]=h[j];
                   }
                else
                  if(zzz(h[j]-h[now])<dis[2]||(zzz(h[j]-h[now])==dis[2]&&h[j]<lasth[2]))
                    {dis[2]=zzz(h[j]-h[now]);
                     next[2]=j;
                     lasth[2]=h[j];
                     }
                }
             if(next[2]==0)
               break;
             if(ka+kb+dis[2]>s)
               break;
             ka+=dis[2];
             now=next[2];
             }
          who=1-who;
          }
       if(kb!=0)
         {if(why==-1.0)
            {why=ka/1.0/kb;
             where=i;
             }
          else
            if(why>ka/1.0/kb)
              {why=ka/1.0/kb;
               where=i;
               }
          }
       }
    printf("%d\n",where);
    
    scanf("%d",&m);
    int x;
    while(m--)
      {scanf("%d%I64d",&x,&s);
       ka=0,kb=0,now=x,who=0;
       while(1)
         {if(who)
            {next[1]=0;
             lasth[1]=10000000000ll;
             dis[1]=10000000000ll;
             for(j=now+1;j<=n;j++)
               {if(zzz(h[j]-h[now])<dis[1]||(zzz(h[j]-h[now])==dis[1]&&h[j]<lasth[1]))
                  {dis[1]=zzz(h[j]-h[now]);
                   next[1]=j;
                   lasth[1]=h[j];
                   }
                }
             if(next[1]==0)
               break;
             if(ka+kb+dis[1]>s)
               break;
             kb+=dis[1];
             now=next[1];
             }
          else
            {next[1]=next[2]=0;
             lasth[1]=lasth[2]=10000000000ll;
             dis[1]=dis[2]=10000000000ll;
             for(j=now+1;j<=n;j++)
               {if(zzz(h[j]-h[now])<dis[1]||(zzz(h[j]-h[now])==dis[1]&&h[j]<lasth[1]))
                  {dis[2]=dis[1];
                   next[2]=next[1];
                   lasth[2]=lasth[1];
                   dis[1]=zzz(h[j]-h[now]);
                   next[1]=j;
                   lasth[1]=h[j];
                   }
                else
                  if(zzz(h[j]-h[now])<dis[2]||(zzz(h[j]-h[now])==dis[2]&&h[j]<lasth[2]))
                    {dis[2]=zzz(h[j]-h[now]);
                     next[2]=j;
                     lasth[2]=h[j];
                     }
                }
             if(next[2]==0)
               break;
             if(ka+kb+dis[2]>s)
               break;
             ka+=dis[2];
             now=next[2];
             }
          who=1-who;
          }
       printf("%I64d %I64d\n",ka,kb);
       }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
