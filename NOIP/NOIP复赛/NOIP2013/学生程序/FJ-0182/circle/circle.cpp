#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m,k,x,q[101],p;
long long ans;
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>x;
	q[1]=k;
	p=1;
	while(q[p]>0)
	{
		p++;
		q[p]=q[p-1]/2;
	}
	p--;
	for(int i=p;i>=1;i--)
	{
		ans=(ans*ans)%n;
		if(q[i]%2==1)ans=(ans*10)%n;
	}
	cout<<(((ans*m)%n)+x)%n<<endl;
	return 0;
}

