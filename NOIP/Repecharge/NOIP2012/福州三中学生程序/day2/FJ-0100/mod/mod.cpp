#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

long long a,b;

int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=90000000;i++)
	{
		if((a*i)%b==1)
		{
			cout<<i<<endl;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
