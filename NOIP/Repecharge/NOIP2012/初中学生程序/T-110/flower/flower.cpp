#include<iostream>
using namespace std;
int main()
{
    int n,m;
    int a[100],b,c,max;
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n>>m;
    max=0;
    for(b=1;b<=n;b++)
     {cin>>a[b];
      max=max+a[b];
     }
    cout<<max-m+1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
