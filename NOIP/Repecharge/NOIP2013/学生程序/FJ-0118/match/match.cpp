#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=99999997;
struct inpu{int a,p;} sd[100010],to[100010],in[100010];
int n;
int que[9999999];
bool cmp(inpu a,inpu b){return a.a<b.a;}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
       scanf("%d",&in[i].a);
       to[i].a=in[i].a;
       to[i].p=i;
    }
    for(i=1;i<=n;i++)
    {
       scanf("%d",&sd[i].a);
       sd[i].p=i;
    }
    sort(sd+1,sd+n+1,cmp);
    sort(to+1,to+n+1,cmp);
    for(i=1;i<=n;i++)
    {
       in[to[i].p].p=sd[i].p-to[i].p;
    }
    int ans=0;
    int head=100000,tail=100000;
    for(i=n-1;i>=1;i--) 
      if(in[i].p>0) 
        que[++tail]=i;
    while(head<tail)
    {
        head++;
        for(j=que[head];j<=n;j++) 
        {
           if(in[j].p==0) break;
           inpu swap;        
           swap=in[j+1];
           in[j+1]=in[j];
           in[j]=swap;
           in[j].p+=1;
           in[j+1].p-=1;
           if(in[j].p>0) que[--head]=j;
           ans+=1;
           ans%=mod;
        }
    }
    printf("%d\n",ans);
    return 0;
    
}
