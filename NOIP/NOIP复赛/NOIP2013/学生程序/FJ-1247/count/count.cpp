#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stdlib.h>
using namespace std;
char a[100],x;
int main()
{
	int s=0,n;
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		itoa(i,a,10);
		for(int j=0;j<strlen(a);j++)
		if(a[j]==x)s++;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
}
