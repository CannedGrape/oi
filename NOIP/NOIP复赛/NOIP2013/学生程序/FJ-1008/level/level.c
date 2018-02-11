#include<stdio.h>
int n,m,a[1001]={},b[1001]={};
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    int i,j,k,l;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
       int anss=0;
       scanf("%d",&b[0]);
       for(j=1;j<=b[0];j++)
          scanf("%d",&b[j]);
       for(l=b[1];l<=b[b[0]];l++)
       {
         int yesorno=0;
         for(k=1;k<=b[0];k++)
            if(b[k]==l) {yesorno=1;break;}
         if(yesorno==0&&anss<a[l]) anss=a[l];
       }
       a[b[1]]=anss+1;
       a[b[b[0]]]=anss+1;
       for(k=2;k<b[0];k++)
          if(a[b[k]]<a[b[1]]) a[b[k]]=a[b[1]];
    }
    int ansa=1;
    for(i=1;i<=n;i++)
       if(a[i]+1>ansa) ansa=a[i]+1;
    printf("%d\n",ansa);
    return 0;
}

