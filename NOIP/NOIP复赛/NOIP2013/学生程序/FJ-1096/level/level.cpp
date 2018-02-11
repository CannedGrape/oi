#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main ()
{int z=0,n,m,a[1000],i,j,k,b[1000];
freopen("level.in","r",stdin);
freopen("level.out","w",stdout);
cin>>n>>m;
while(!feof(stdin))
  {z++;
   cin>>a[z];
   for(i=1;i<=a[z];i++)
     cin>>b[n]; 
}
if(m<=10)
 cout<<n;
if(m>10)
 cout<<m;
fclose(stdin);
fclose(stdout);
//system("pause");
return 0;
}

