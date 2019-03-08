#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int a[1001],n;
bool pd()
{
     int i;
     for(i=1;i<=n-1;i++)
       if(a[i]+1!=a[i+1])
         return false;
     return true;
}
int main()
{
    int i;
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    cin>>n;
    cin>>n;
    cin>>n;
    for(i=1;i<=n;i++)
      cin>>a[i];
    if(pd()==false) cout<<"2"<<endl;
    else cout<<"1"<<endl;
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
