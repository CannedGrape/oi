#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main ()
{int l,j,x,n,i,t=1,z=0;
freopen("count.in","r",stdin);
freopen("count.out","w",stdout);
cin>>n>>x;
l=n;
for(i=1;i<=6;i++)
    if(l/10!=0)
      {t++;
      l=l/10;
      }
    else
      break;
for(i=1;i<=n;i++)
  {l=i;
  for(j=1;j<=t;j++)
    {if(l%10==x)
      z++;
    l=l/10;
    }
  }
cout<<z;
fclose(stdin);
fclose(stdout);
//system("pause");
return 0;
}
