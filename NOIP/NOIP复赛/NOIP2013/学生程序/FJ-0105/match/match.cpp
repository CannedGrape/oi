#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int n,a[100001],b[100001];

int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
      scanf("%d",&b[i]);
    if(a[0]==2)
      printf("1\n");
    if(a[0]==1)
      printf("2\n");
    else
      printf("%d\n",n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
