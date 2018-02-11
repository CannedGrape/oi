#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
char a[2000000],c[100001];
long long anss=0;
int b[100001];
int n;
int js=0,js2=0,js3=1,k,lzw=0;
int main()
{
  freopen("expr.in","r",stdin);
  freopen("expr.out","w",stdout);
  cin>>a;
  n=strlen(a)-1;
  for(int i=0;i<=n;i++)
    {
    if(a[i]=='*'||a[i]=='+')
      {
      js2++;
      if(a[i]=='*')
        c[js2]='*';
        else
          c[js2]='+';
      }
      else
        if(a[i]!=' ')
          {
          k=i;
          while(a[k+1]!='*'&&a[k+1]!='+'&&k<n)
            k++;
          lzw=0;
          js3=1;
          for(int j=k;j>=i;j--)
            {
            lzw=lzw+(a[j]-48)*js3;
            js3=js3*10;
            if(js3>=10000)
              break;
            }
          js++;
          b[js]=lzw;
          for(int j=i;j<=k;j++)
            a[j]=' ';
          } 
      }
  for(int i=1;i<=js2;i++)
    if(c[i]=='*')
      {
      b[i+1]=(b[i]*b[i+1])%10000;
      b[i]=0;
      }
  
  for(int i=1;i<=js;i++)
    anss=anss+b[i];
  anss=anss%10000;
  cout<<anss;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
