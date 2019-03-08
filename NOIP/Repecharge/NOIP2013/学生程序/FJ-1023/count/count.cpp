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
int main()
{freopen("count.in","r",stdin);
 freopen("count.out","w",stdout);
 int n,m,i,j,s=0;
 cin>>n>>m;
 for(i=1;i<=n;i++)
  if(n/cy(i)<10)
  {j=i;
   break;
   }
 if(m!=0)
 {for(i=1;i<=j+1;i++)
  {s+=n/cy(i)*cy(i-1);
   if(n%cy(i)/cy(i-1)==m) 
   {if(i==1) s+=1;
    if(i>1) s+=n%cy(i-1)+1;
   }
  }
 }
 cout<<s;
 fclose(stdin);
 fclose(stdout);
 //system("pause");
 return 0;
}
