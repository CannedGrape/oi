#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int n,lb,m=0,maxn;
long tot=0,zi=0;
void doit(int x)
{
   zi++;
   if(b[1]==0&&x==1) zi--;
   if(b[n]==0&&x==n) zi--;
   b[x]=1;
   if(b[x-1]==1) zi--;
   if(b[x+1]==1) zi--;
}
void xiao(int x,int y)
{
     tot++;
     for(int k=x+1;k<y;k++)
        a[k]--;
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&n);
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
       {scanf("%d",&a[i]);
        if(a[i]>m) {m=a[i];maxn=i;}
        if(a[i]==0) doit(i);
       }
    while(a[maxn]>0)
       {tot=tot+zi+1;
        for(int j=1;j<=n;j++)
           {if(a[j]!=0) 
               {a[j]--;
                if(a[j]==0) doit(j);
               }
           }
       }
    printf("%ld\n",tot);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
