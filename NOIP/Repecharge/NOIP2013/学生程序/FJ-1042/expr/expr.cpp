#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
string s;
int cheng,len,now,last,ans,tot,a[100002];
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    cin>>s;
    len=s.size();
    for (int i=0; i<len; ++i)
    {
          if (s[i]>=48)
              now=(now*10+s[i]-48)%10000;
              
          if (s[i]=='*')
          { 
              if (cheng) now*=last%10000; 
              last=now%10000; 
              now=0; 
              cheng=1;
          }
          if (s[i]=='+')
          { 
              if (cheng) now=now*last%10000;
              a[++tot]=now%10000;
              now=0;
              cheng=0;
          }
    }
    if (cheng) now*=last%10000;
    ans=now;
    //printf("%d\n",ans);
    for (int i=1; i<=tot; ++i)
    {
        ans=(ans+a[i])%10000;
    }
    printf("%d",ans);
    fclose(stdin); fclose(stdout);
}
