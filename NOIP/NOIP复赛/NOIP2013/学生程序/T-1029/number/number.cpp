#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,p,i,j,a[1001],b[1001],max;
    cin>>n>>p;
    for(i=1;i<=n;i++)
      {cin>>a[i];
       b[i]=a[i];
      }
    for(i=2;i<=n;i++)
      for(j=1;j<=i;j++)
        {max=a[1];
         if()
           b[i]=max;
        }
    for(i=2;i<=n;i++)
      b[i]=b[i]+b[i-1];
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        {if(b[i]>=b[j])
           max=b[i];
         else
           max=b[j];
        }
    if(max>0)
      max=max*(-1);
    cout<<max%p;
    fclose(stdin);
    fclose(stdout);
    system("pause");
    return 0;
}
