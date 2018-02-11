#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
int main()
{ freopen("prime.in","r",stdin);
  freopen("prime.out","w",stdout);
  int n,i;
  cin>>n;
  for(i=3;i<=sqrt(n);i++)
   if(n%i==0)
   { cout<<n/i<<endl;
     break;
   }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
