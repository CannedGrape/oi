#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<string>
using namespace std;
int n,ans=0,k1=-2,ans2=0;
bool flag;
int a[100001];
int main()
{
freopen("flower.in","r",stdin);freopen("flower.out","w",stdout);
scanf("%d",&n);
for (int q=0;q<n;q++) scanf("%d",&a[q]);
a[n]=-1;
for (int q=0;q<n;q++)
{
  flag=0;
  while (a[q+1]>a[q])
  {
   q++;
   flag=1;
  }
  if (flag==1 && q!=n-1) 
  {
   if (q-1==k1+1) ans--; 
   ans+=3;
   k1=q;
  }
  if (flag==1 && q==n-1)
  {
   if (q-1==k1+1) ans--; 
   ans+=2;
  }
}

a[n]=100000000;
k1=-2;
for (int q=0;q<n;q++)
{
  flag=0;
  while (a[q+1]<a[q])
  {
   q++;
   flag=1;
  }
  if (flag==1 && q!=n-1) 
  {
   if (q-1==k1+1) ans2--; 
   ans2+=3;
   k1=q;
  }
  if (flag==1 && q==n-1)
  {
   if (q-1==k1+1) ans2--; 
   ans2+=2;
  }
}


if (ans2>ans) ans=ans2;
if (ans==0) ans=1;
printf("%d\n",ans);
fclose(stdin);fclose(stdout);
return 0;
}
