#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std; 
int ans[10001]={};
bool flag[10001]={};
int min(int a,int b)
{
    if(a>b)
    return b;
    else 
    return a;
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int j,top,end,n,m,i,q;
    int dt,dw,d[20001]={};
    cin>>n>>m;
    int h[50001]={},t[50001]={},v[50001]={};
    for(i=1;i<=m;i++)
    {
    scanf("%d%d%d",&h[i],&t[i],&v[i]);
    }
    cin>>q;
    while(q>0)
    {
    for(i=1;i<=n;i++)
    ans[i]=-1;
    q--;
    dt=1;
    dw=1;
    cin>>top>>end;
    d[1]=top;
    flag[top]=1;
    ans[top]=100001;
    while(dt<=dw || dt>dw+1)
    {
    for(j=1;j<=m;j++)
    {if(h[j]==d[dt])
    if(min(ans[dt],v[j])>ans[t[j]])
    {
    ans[t[j]]=min(ans[dt],v[j]);
    if(flag[t[j]]==0)
    {dw++;
    if(dw>20000)
    dw=1;
    d[dw]=t[j];
    flag[t[j]]=1;
    }
    }
    if(t[j]==d[dt])
    if(min(ans[dt],v[j])>ans[h[j]])
    {
    ans[h[j]]=min(ans[dt],v[j]);
    if(flag[h[j]]==0)
    {dw++;
    if(dw>20000)
    dw=1;
    d[dw]=h[j];
    flag[h[j]]=1;
    }
    }
    
    }
    
    flag[dt]=0;
    dt++;
    if(dt>20000)
    dt=1;
    }
    printf("%d\n",ans[end]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;    
}
