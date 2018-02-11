#include<iostream>
#include<cstdio>
using namespace std;
int n=0,a[10001]={},p=1;
bool b[45001]={};
int main()
{   freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    cin>>n;
    a[p]=2;
    b[2]=true;
    int i=0,j=0;
    for(i=1;i<=p;i++)
      {for(j=a[p];j<=45000;j+=a[p])
         b[j]=true;
       for(j=a[p]+1;j<=45000;j++)
         if(b[j]==false)
           {++p;
            a[p]=j;
            break;
           }
      }
    for(i=1;i<=p;i++)
      if(n%a[i]==0)
        {cout<<n/a[i]<<endl;
         break;
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
