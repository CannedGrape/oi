#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;
int n;
long long mylast[4100],mynow[4100],ans[4100],al,ll,nl;
struct pii
{
    int a,b,m;
} w[1001];
int cmp(pii i,pii j)
{
    if (i.m<j.m) return 1;
    return 0;
}
void myche(int k)
{
    int i;
    for (i=ll+1;i<=4099;i++)
      mylast[i]=0;
    for (i=1;i<=ll;i++)
      mylast[i]=mylast[i]*k;
    for (i=1;i<=ll;i++)
    {
        if (mylast[i]>10)
        {
            mylast[i+1]+=mylast[i]/10;
            mylast[i]=mylast[i]%10;
            if (i==ll) ll++;
        }
    }
}
void mychu(long long k)
{
    long long i,j=0;
    nl=0;
    for (i=ll;i>=1;i--)
    {
        mynow[i]=0;
        j=j*10+mylast[i];
        if (j/k!=0)
        {
            if (nl==0) nl=i;
            mynow[i]=j/k;
            j=j%k;
        }
    }
}
bool mycmp()
{
    if (nl>al) return true;
    if (nl<al) return false;
    for (int i=nl;i>=1;i--)
    {
        if (mynow[i]>ans[i]) return true;
        if (mynow[i]<ans[i]) return false;
    }
    return false;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    int i,j;
    cin>>w[0].a>>w[0].b;
    w[0].m=w[0].a*w[0].b;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&w[i].a);
        scanf("%d",&w[i].b);
        w[i].m=w[i].a*w[i].b;
    }
    sort(w+1,w+n+1,cmp);
    mylast[1]=1;
    ll=1;
    for (i=1;i<=n;i++)
    {
        myche(w[i-1].a);
        mychu(w[i].b);
        if (mycmp())
        {
            al=nl;
            for (j=1;j<=nl;j++)
              ans[j]=mynow[j];
        }
    }
    for (i=al;i>=1;i--)
      cout<<ans[i];
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
