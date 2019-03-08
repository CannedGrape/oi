#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
char a[8];
int sum=0;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		itoa(i,a,10);
		for(int qc=0;qc<strlen(a);qc++)
		{
			if((a[qc]-48)==x)
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return(0);
}
