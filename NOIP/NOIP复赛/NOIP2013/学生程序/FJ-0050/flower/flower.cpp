#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
int n,h[100010],ans=0;
//int f1[100010],f2[100010];
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i,j,pf1=1,pf2=1;
    bool p;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&h[i]);
    /*
    f1[1]=1;
    for (i=2;i<=n;i++)
    {
        for (j=1;j<i;j++)
        {
            if (h[j]>h[i] && f1[j]%2==1)
               f1[i]=max(f1[i],f1[j]+1);
            if (h[j]<h[i] && f1[j]%2==0)
               f1[i]=max(f1[i],f1[j]+1);
            ans=max(ans,f1[i]);
        }
    }
    f2[1]=1;
    for (i=2;i<=n;i++)
    {
        for (j=1;j<i;j++)
        {
            if (h[j]>h[i] && f2[j]%2==0)
               f2[i]=max(f2[i],f2[j]+1);
            if (h[j]<h[i] && f2[j]%2==1)
               f2[i]=max(f2[i],f2[j]+1);
            ans=max(ans,f2[i]);
        }
    }
    */
    p=0;
    for (i=1;i<n;i++)
    {
        if (h[i]>h[i+1] && p==0)
        {
           pf1++;
           p=1;
        }
        if (h[i]<h[i+1] && p==1)
        {
           pf1++;
           p=0;
        }
    }
    p=1;
    for (i=1;i<n;i++)
    {
        if (h[i]>h[i+1] && p==0)
        {
           pf2++;
           p=1;
        }
        if (h[i]<h[i+1] && p==1)
        {
           pf2++;
           p=0;
        }
    }
    ans=max(pf1,pf2);
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
