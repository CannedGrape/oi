#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;
int main()
{
 freopen("classroom.in","r",stdin);
 freopen("classroom.out","w",stdout);
 long long n,m;
 long long s[10000],d[10000],t[10000],r[10000];
 long long i,j;
 cin>>n>>m;
 for(i=1;i<=n;i++)
   cin>>r[i];
 for(i=1;i<=m;i++)
   cin>>d[i]>>s[i]>>t[i];
 for(i=1;i<=m;i++)
   {for(j=s[i];j<=t[i];j++)
    {r[j]=r[j]-d[i];
     if(r[j]<0)
     {cout<<"-1"<<endl;
      cout<<i;
      fclose(stdin);
      fclose(stdout);
      return 0;
     }
    }
   }
 cout<<"0";
 fclose(stdin);
 fclose(stdout);
 return 0;
}
