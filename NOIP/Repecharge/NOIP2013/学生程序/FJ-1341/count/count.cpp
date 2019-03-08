#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
		freopen("count.out","w",stdout);
		int x,n;
		cin>>x>>n;
		for(x=0;x>=100;x++)
		{
			n=n+x;
		}
		cout<<n<<endl;
		return 0;
}
