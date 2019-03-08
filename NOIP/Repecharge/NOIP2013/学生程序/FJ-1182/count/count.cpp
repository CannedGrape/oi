#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int m,n,x,i,a;
	a=0;
	cin>>n>>x;
	for(i=1;i<=n;i++)
	{
		m=i;
		while(m!=0)
		{
			if(m%10==x) a++;
		    m=m/10;
		}
	}
	cout<<a<<endl;
	return 0; 
} 
