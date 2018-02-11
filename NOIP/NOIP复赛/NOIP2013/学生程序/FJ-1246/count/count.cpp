#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int j,n,i,sum=0;
char x,a[10]={'\0'};
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>x;
	for(i=1;i<=n;i++)
	{
		itoa(i,a,10);
		for(j=0;j<strlen(a);j++)
		if(a[j]==x) sum++; 
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
