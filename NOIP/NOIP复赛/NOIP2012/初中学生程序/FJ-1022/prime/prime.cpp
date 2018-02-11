#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int p(int i)
{
    int j;
    for(j=2;j<=i/2+1;j++) if (i%j==0) return 0;
    return 1;
}
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    cin>>n;
    int i;
    if (n%2==0) 
      {if (n==2) cout<<2; else cout<<n/2;
      return 0;
      }
    if (p(n)==1) {cout<<n;  return 0;}
    for(i=3;i<=n;i=i+2)
     if (n%i==0)
       if((p(i)==1)&&(p(n/i)==1)) {cout<<n/i; break;}
     fclose(stdin);
     fclose(stdout);
  //  system("pause");
    return 0;
}
