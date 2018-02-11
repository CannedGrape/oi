#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
int get()
{
	int f=0,v=0;char ch;
	while(!isdigit(ch=getchar()))if(ch=='-')break;
	if(ch=='-')f=1;else v=ch-'0';
	while(isdigit(ch=getchar()))v=v*10+ch-'0';
	if(f==1)return -v;else return v;
}
typedef long long LL;
LL n,m,k,x;

LL Pow(LL a,LL b)
{
	LL res=1;
	for(;b;b/=2,a=a*a%n)
		if(b&1)res=res*a%n;
	return res;
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin>>n>>m>>k>>x;
	cout<<(x+m*Pow(10ll,k)%n)%n<<endl;
	return 0;
}
