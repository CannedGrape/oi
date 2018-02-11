#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,k,x;
int mod(double y)
{ int _;
  double __=n;
  for(_=5;_>=0;_--)
   while(y>=__*pow(10,_))
    y-=__*pow(10,_);
  return y;
}
int fastpow()
{ double s=1,y=10;
  while(k)
  { if(k&1)
     s=mod(s*y);
    y=mod(y*y);
    k/=2;
  }
  m=mod(m*s);
  return (m+x)%n;
}
int main()
{ freopen("circle.in","r",stdin);
  freopen("circle.out","w",stdout);
  cin>>n>>m>>k>>x;
  cout<<fastpow()<<endl;//(m*10^k+x)%n
  fclose(stdin);
  fclose(stdout);
  return 0;
}
