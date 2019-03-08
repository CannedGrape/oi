#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstring>
#include<queue>
using namespace std;
int n,m,k,x;
void small()
{
	for(unsigned long long i=1,xx=x;i<=10;i++)
	{
		xx=(xx+m)%n;
		m=xx;
	}
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&x);
	
	int ji=1;
	while(ji<k)
	{
		small();
		ji++;
	}
	for(unsigned long long i=1;i<=pow(10,k-ji+1);i++)x=(x+m)%n;
	cout<<x<<endl;
	return 0;
}
