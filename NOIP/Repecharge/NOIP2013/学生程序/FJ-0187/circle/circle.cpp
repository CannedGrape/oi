#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k,x;
long long ksm(long long a,int b)
{
	long long i,t=a,c=b,ans=1;
	for(;c>0;)
	{
	if(c%2==1) ans=(ans*t)%n;
	t=(t*t)%n;
	c/=2;
    }
    return ans;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	long long w;
	int i,temp=0;
	cin>>n>>m>>k>>x;
	for(i=1;i<=10;i++)
	{temp+=m;temp%=n;}
	w=(long long)(ksm(10,k-1)*temp)%n;
	w=(w+x)%n;
	cout<<w;
	return 0;
}
