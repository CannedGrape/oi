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
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int i,n,x,sum=0,a[1000001];
    cin>>n>>x;
    for(i=1;i<=n;i++)
      a[i]=i;
    for(i=1;i<=n;i++)
      if((a[i]%10==1)||(a[i]/10==1)||(a[i]/100==1)||(a[i]/1000==1)||(a[i]/10000==1)||(a[i]/100000==1))
        sum+=1;
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    system("pause");
    return 0;
}
