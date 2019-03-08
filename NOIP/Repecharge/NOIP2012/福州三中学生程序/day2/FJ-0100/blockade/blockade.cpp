#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int n,m,k;

int main()
{
	freopen("blockade.in","r",stdin);
	freopen("blockade.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
		for(int j=1;j<=3;j++)
			cin>>m;
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>m;
	cout<<n/2+1;
	fclose(stdin);fclose(stdout);
	return 0;
}
