#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int cy(int a)
{int i,s=1;
 for(i=1;i<=a;i++)
  s*=10;
 return s;
}
long long n=0,m=0,i,j;
bool f[100001]={};
long long a[100001]={},b[100001]={},c[100001]={},k[100001]={};
int main()
{freopen("expr.in","r",stdin);
 freopen("expr.out","w",stdout);
 string s;
 cin>>s;
 for(i=0;i<=s.length()-1;i++)
  if(s[i]=='+'||s[i]=='*') 
  {f[i]=true;
   m++;
   a[m]=i;
   if(s[i]=='*') k[i]=m;
   }
 for(j=a[1]-1;j>=0;j--)
  b[1]+=cy(a[1]-1-j)*(s[j]-'0');
 for(i=2;i<=m;i++)
  for(j=a[i]-1;j>=a[i-1]+1;j--)
   b[i]+=cy(a[i]-1-j)*(s[j]-'0');
 for(j=s.length()-1;j>=a[m]+1;j--)
  b[m+1]+=cy(s.length()-1-j)*(s[j]-'0');
 for(i=1;i<=m;i++)
  b[i]=b[i]%10000;
 for(i=1;i<=s.length()-1;i++)
  if(s[i]=='*')
  {b[k[i]]=b[k[i]]*b[k[i]+1]%10000;
   for(j=k[i]+1;j<=m+1;j++)
    b[j]=b[j+1];
   m--;
   for(j=i;j<=s.length()-1;j++)
    s[j]=s[j+2];
   for(j=1;j<=s.length()-1;j++)
   {k[j]=k[j+2];
    k[j]--;
    }
  }
 for(i=1;i<=m+1;i++)
  n+=b[i];
 cout<<n%10000;
 fclose(stdin);
 fclose(stdout);
 //system("pause");
 return 0;
}
