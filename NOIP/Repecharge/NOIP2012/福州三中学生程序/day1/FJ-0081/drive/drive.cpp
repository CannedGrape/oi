#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;
int n,m,h[1001],x0,x[10001],s[10001];
struct
{
    int na,nb,va,vb;
} c[1001];
void init()
{
    cin>>n;
    int i,j,k;
    for (i=1;i<=n;i++)
      scanf("%d",&h[i]);
    cin>>x0;
    cin>>m;
    for (i=1;i<=m;i++)
    {
        scanf("%d",&s[i]);
        scanf("%d",&x[i]);
    }
    for (i=1;i<=n-1;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            k=max(h[i],h[j])-min(h[i],h[j]);
            if (k<c[i].vb || (k==c[i].vb && h[j]<h[c[i].nb]) || c[i].vb==0)
            {
                c[i].na=c[i].nb;
                c[i].va=c[i].vb;
                c[i].nb=j;
                c[i].vb=k;
            }
            else
            {
                if (k<c[i].va || (k==c[i].va && h[j]<h[c[i].na]) || c[i].va==0)
                {
                    c[i].va=k;
                    c[i].na=j;
                }
            }
        }
    }
}
void mainn()
{
    int i,j,k;
    long long aa,bb,hh,as=0,bs=0;
    int ss=0;
    h[0]=-1000000001;
    for (i=1;i<=n;i++)
    {
        aa=0;
        bb=0;
        hh=0;
        j=i;
        k=1;
        while (j!=0)
        {
            if (k==1)
            {
                if (hh+c[j].va<=x0)
                {
                    hh+=c[j].va;
                    aa+=c[j].va;
                    j=c[j].na;
                }
                else break;
            }
            else
            {
                if (hh+c[j].vb<=x0)
                {
                    hh+=c[j].vb;
                    bb+=c[j].vb;
                    j=c[j].nb;
                }
                else break;
            }
            k=(k+1)%2;
        }
        if (aa*bs<bb*as || (aa*bs==bb*as && h[i]>h[ss]) && !(bb==0 && bs!=0))
        {
            ss=i;
            as=aa;
            bs=bb;
        }
    }
    cout<<ss<<endl;
    for (i=1;i<=m;i++)
    {
        aa=0;
        bb=0;
        hh=0;
        j=s[i];
        k=1;
        while (j!=0)
        {
            if (k==1)
            {
                if (hh+c[j].va<=x[i])
                {
                    hh+=c[j].va;
                    aa+=c[j].va;
                    j=c[j].na;
                }
                else break;
            }
            else
            {
                if (hh+c[j].vb<=x[i])
                {
                    hh+=c[j].vb;
                    bb+=c[j].vb;
                    j=c[j].nb;
                }
                else break;
            }
            k=(k+1)%2;
        }
        cout<<aa<<" "<<bb<<endl;
    }
}
int main()
{
    freopen("drive.in","r",stdin);
    freopen("drive.out","w",stdout);
    init();
    mainn();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
