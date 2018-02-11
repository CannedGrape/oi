#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;
int n,m;
int r[1000001],d[1000001],s[1000001],t[1000001];

template<class T>
void myread(T &xx)
{
    char yy;
    xx=0;
    while (!isdigit(yy=getchar()));
    xx=yy-'0';
    while (isdigit(yy=getchar()))
      xx=xx*10+yy-'0';
}

void init()
{
    myread(n);
    myread(m);
    int i;
    for (i=1;i<=n;i++)
      myread(r[i]);
    for (i=1;i<=m;i++)
    {
        myread(d[i]);
        myread(s[i]);
        myread(t[i]);
    }
}
void baosou()
{
    int i,j;
    for (i=1;i<=m;i++)
    {
        for (j=s[i];j<=t[i];j++)
        {
            if (r[j]<d[i])
            {
                cout<<-1<<endl<<i<<endl;
                return;
            }
            else r[j]-=d[i];
        }
    }
    cout<<0<<endl;
}
long long rn[1000010]={};
bool check(int k)
{
    int i,j;
    for (i=1;i<=n;i++)
      rn[i]=0;
    for (i=1;i<=k;i++)
    {
        rn[s[i]]+=d[i];
        rn[t[i]+1]-=d[i];
    }
    j=0;
    for (i=1;i<=n;i++)
    {
        j+=rn[i];
        if (r[i]<j) return true;
    }
    return false;
}
int find(int ll,int rr)
{
    int i;
    if (ll==rr-1)
    {
        if (check(ll)) return ll;
        else return rr;
    }
    if (ll==rr) return ll;
    i=(rr-ll)/2+ll;
    if (check(i)) return find(ll,i);
    return find(i,rr);
}
void mainn()
{
    int i,j,k;
    for (i=1;i<=m;i++)
    {
        rn[s[i]]+=d[i];
        rn[t[i]+1]-=d[i];
    }
    j=0;
    k=1;
    for (i=1;i<=n;i++)
    {
        j+=rn[i];
        if (r[i]<j)
        {
            k=0;
            break;
        }
    }
    if (k==1) cout<<0<<endl;
    else cout<<-1<<endl<<find(1,m)<<endl;
}
int main()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    init();
    if (n<=1000) baosou();
    else mainn();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
