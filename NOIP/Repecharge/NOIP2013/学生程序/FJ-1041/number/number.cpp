#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int jjfly(int const &x,int const &y){return x>y;}
int n,p,i,j,k,a[10000000],b[10000000],c[10000000],ma=-2147483647,total=0,ans=-2147483647,f[10000000],baga=0,tot=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;i++)
    {
    scanf("%d",&a[i]);
    total=0;
    memset(b,0,sizeof(b));
    for(j=1;j<=i;j++)
    {
    total+=a[j];
    b[j]=total;
    if (j==i){
    for(k=1;k<=i;k++)
    if (b[k]>ma) ma=b[k];
    c[i]=ma;}}}
    ans=f[1];
    f[1]=c[1];
    for(i=2;i<=n;i++){
    for(j=i;j>=1;j--)
    {f[j]=f[j-1]+c[j-1];
    if (f[j]>ans) ans=f[j];}}
    printf("%d\n",ans%p);
   fclose(stdin);fclose(stdout);
    return 0;
}
