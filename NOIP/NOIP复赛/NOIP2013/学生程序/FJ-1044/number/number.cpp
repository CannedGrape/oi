#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int main()
{
    long long n,p,i;
    long long a[1001];
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>p;
    for(i=1;i<=n;i++)
      cin>>a[i];
    cout<<a[1]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
