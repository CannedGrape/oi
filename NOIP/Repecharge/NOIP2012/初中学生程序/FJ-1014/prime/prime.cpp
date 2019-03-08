#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    int n,m,i;
    cin>>n;
    m=int(sqrt(double(n)+0.5));
    for(i=m;i<n;i++)
      if(n%i==0)
       {
        cout<<i<<endl;
        break;
       }
    fclose(stdout);
    fclose(stdin);
    //system("pause");
    return 0;
}
