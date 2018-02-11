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
	freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		int n,p;
		cin>>n>>p;
		for(n=1;n<=100;n++)
		{
			p=p+n;
		}
		cout<<p<<endl;
		return 0;
}
