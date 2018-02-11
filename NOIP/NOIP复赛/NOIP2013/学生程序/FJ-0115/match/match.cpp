#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,tot=0,m=0;
long long a[10001]={},b[10001]={},cz[10001][10001]={};
bool hl=true;
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int i,j;
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (j=1;j<=n;j++)
        {cin>>b[j];
         if (b[j]!=a[j])
         {hl=false;tot++;}
         }
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        cz[i][j]=(a[i]-b[j])*(a[i]-b[j]);
    if (hl==true)
      cout<<"0"<<endl;
    else 
      cout<<(tot-1)%99999997<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
