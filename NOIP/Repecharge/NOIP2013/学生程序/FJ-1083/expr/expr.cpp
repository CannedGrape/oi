#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char a;
long long x,s[100001],ans;
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    s[0]=x=1;
    while(scanf("%c",&a),a!='\n')
      {
      if(a<='9' && a>='0')
        s[x]=s[x]*10+int(a)-48;
      if(a=='+')
        {
        for(int i=1;i<=x;i++)
          s[0]*=s[i],s[0]%=10000,s[i]=0;
        x=1,ans+=s[0],s[0]=1;
        }
      if(a=='*')
        x++;
      }
    for(int i=1;i<=x;i++)
      s[0]*=s[i],s[0]%=10000,s[i]=0;
    x=1,ans+=s[0],ans%=10000;
    cout<<ans<<endl;
    return 0;
}
