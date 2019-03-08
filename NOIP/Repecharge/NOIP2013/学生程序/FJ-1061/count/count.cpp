#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,x;
int a,b,c,d,sum=0;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>x;
	for(a=1;a<=n;a++)
	{
		b=a;
		while(b>=10)
		{
			if(b%10==x)
				sum++;
			b/=10;
		}
		if(b==x)
			sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
