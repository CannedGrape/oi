#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,m,k,x,tot=1;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int i;
    cin>>n>>m>>k>>x;
    for (i=1;i<=k;i++)
      tot*=10;
    if (n%2==0)
      {if (m%2==0) tot=tot%n;
       else tot=tot%(n/2);
       }
    else
      tot=tot%n;
    if (tot!=0)
      {
        for (i=1;i<=tot;i++)
          {
            if (x+m>n-1)
              x=x+m-n;
            else
              x=x+m;
          }
      }
    if (tot==0)
      x=x;
    cout<<x<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
