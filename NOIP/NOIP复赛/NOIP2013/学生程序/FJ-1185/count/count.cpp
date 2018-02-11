#include <iostream>
#include <cstdio>
using namespace std;
long long a[8]={0},z=0;
int main()
{
freopen ("count.in","r",stdin);
freopen ("count.out","w",stdout);
int n,x,c=1; scanf ("%d%d",&n,&x);
for (int k=1;k<=1000000;k++)
{
if (k>n)break;
a[1]++;
for (int j=1;j<=6;j++)
if (a[j]==10) {a[j]=0;a[j+1]++; if (j+1>c)c=j+1;} else break;
for (int i=1;i<=c;i++)
if (a[i]==x)z++; 
}
printf ("%d\n",z);
return 0;
}

