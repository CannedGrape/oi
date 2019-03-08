#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n;
	char x;
	cin>>n>>x;
	char digbuf[8];
	string digstr;
	for (int i=1;i<=n;i++)
	{
		sprintf(digbuf,"%d",i);
		digstr+=digbuf;
	}
	cout<<count(digstr.begin(),digstr.end(),x)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}