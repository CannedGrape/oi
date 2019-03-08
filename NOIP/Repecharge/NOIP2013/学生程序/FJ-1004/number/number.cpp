#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
long long i,j,k,n,p,a[1000005],s,m=-2147483600,ss,s1,ma;
int main()
{freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
 cin>>n>>p>>s;s1=s;ma=s;
 for(i=2;i<=n;i++)
    {s+=j;
     cin>>j;
     ss+=s1;if(ss>ma)ma=ss;
     s1=s;
    }ss+=s1;if(ss>ma)ma=ss;
 cout<<ma%p;
 fclose(stdin);
 fclose(stdout);
 return 0;
}
