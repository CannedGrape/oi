#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

int a[100001],b[100001];

int n,ans=0;
int main()
{
freopen("match.in","r",stdin); freopen("match.out","w",stdout);
scanf("%d",&n);
for (int q=0;q<n;q++)   scanf("%d",&a[q]);  
for (int q=0;q<n;q++)   scanf("%d",&b[q]); 

for (int q=0;q<n-1;q++)
 for (int p=q+1;p<n;p++)
  if (a[q]*b[p]+a[p]*b[q]>a[q]*b[q]+a[p]*b[p])
   {
    swap(b[q],b[p]);
     ans++;
     ans=ans%99999997;
   }
printf("%d\n",ans);
fclose(stdin);fclose(stdout);

return 0;
} 
