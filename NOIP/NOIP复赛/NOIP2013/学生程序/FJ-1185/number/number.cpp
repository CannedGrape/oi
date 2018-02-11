#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long a[1000001],s[1000001],d[1000001],n,p;
int main()
{
freopen ("number.in","r",stdin);
freopen ("number.out","w",stdout);
int i=0,j=0,k=0,l=0,t=0,mx=-1000000001;
scanf ("%d%d",&n,&p);
cin >>a[1];  l+=a[1];  s[1]=a[1]; 
for (int q=2;q<=n;q++) 
{scanf ("%d",&a[q]); l+=a[q]; t=l;
for (int w=1;w<=q;w++)
{
k+=a[w];l-=a[w];
if (k>mx&&k!=0) mx=k;if (l>mx&&l!=0) mx=l;
}
s[q]=mx; mx=-1000000001; k=0; l=t;
}
d[1]=a[1]; mx=-2000000002;
if (d[1]>mx)mx=d[1];
for (int q=2;q<=n;q++)
{
d[q]=s[q-1]+d[q-1];
if (d[q]>mx)mx=d[q];
}
if (mx<0)printf("-");
mx=abs(mx); 
mx%=p;
printf("%d\n",mx);
return 0;
}
