#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100001];
int b[100001];
long long n;
long long tot;
int cmp(int a,int b)
{
     if(a>b)
       tot++;
     return a-b;
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    tot=0;
    cin>>n;
    int i,j;
    long long tot1,tot2;
    for(i=0;i<=n-1;i++)
      cin>>a[i];
    for(j=0;j<=n-1;j++)
      cin>>b[j];
    sort(a,a+n-1,cmp);
    tot1=tot;
    tot=0;
    sort(b,b+n-1,cmp);
    tot2=tot;
    if(tot2>tot1)
      cout<<tot2-tot1<<endl;
    else
    cout<<tot1-tot2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
