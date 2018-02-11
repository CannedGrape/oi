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
 freopen("mod.in","r",stdin);
 freopen("mod.out","w",stdout);
 long long a,b,x;
 cin>>a>>b;
 x=1;
 while((a*x)%b!=1)
   x++;
 cout<<x;
 fclose(stdin);
 fclose(stdout);
 return 0;
}
