#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>

using namespace std;
typedef long long ll;

ll n,m,k,x;

ll Pow(ll a,ll b,ll c){
 ll ret=1;
 while(b){
  if(b&1) ret=(ret*a)%c;
  a=(a*a)%c;
  b>>=1;
 }
 return ret;
}

int main(){
 freopen("circle.in","r",stdin);
 freopen("circle.out","w",stdout);
 cin>>n>>m>>k>>x;
 ll p=Pow(10,k,n);
 cout<< ((p*m%n)+x)%n<<endl;
 return 0;
}
