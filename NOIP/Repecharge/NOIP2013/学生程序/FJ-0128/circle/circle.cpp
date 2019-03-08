#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdio>
using namespace std;
int main()
{freopen("circle.in","r",stdin);
freopen("circle.out","w",stdout);
  int n,m,k,x,s=1,i;
  scanf("%d%d%d%d",&n,&m,&k,&x);
    for(i=1;i<=k;i++)
    s=(s*10)%n;
    s=(s*m)%n;
   s=(s+x)%n; 
    cout<<s;
 fclose(stdin);
 fclose(stdout);   
    //system("pause");
    return 0;
    }
