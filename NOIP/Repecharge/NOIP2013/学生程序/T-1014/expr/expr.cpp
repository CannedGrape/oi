#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    char
        str[100000];
    int
       a[4],
       b[4],
       c,
       n;
    cin.getline(str,100000);
    n=strlen(str);
    for(int i=0;i<=n;i++)
    {
        if(str[i]=='*')
        {
            for(int j=0;j<4;j++)
            {
                if(str[i-j]=='*' && str[i-j]=='+')
                  break;
                else
                  a[j]=str[i-j]-'0';
            }
            for(int j=0;j<4;j++)
            {
                if(str[i+j]=='*' && str[i+j]=='+')
                  break;
                else
                  a[j]=str[i+j]-'0';
            }
        }
    }
    return 0;
}
