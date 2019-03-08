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
	freopen("level.in","r",stdin);
		freopen("level.out","w",stdout);
		int n,m;
		cin>>n>>m;
        for(n=1;n>=100;n++)
		{
			m=m+n;
        }
        cout<<m<<endl;
		return 0;
}
