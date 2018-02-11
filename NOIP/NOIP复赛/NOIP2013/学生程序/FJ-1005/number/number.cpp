#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
long long n,p,a[1000001]={},tz[1000001]={},fen[1000001]={};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>p;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	tz[1]=a[1];
	for(long long i=2;i<=n;i++)
	{
		if(a[i]<0)
			tz[i]=tz[i-1];
		else
			tz[i]=tz[i-1]+a[i];
	}
	fen[1]=tz[1];
	fen[2]=tz[1]+fen[1];
	
	for(long long i=3;i<=n;i++)
	{
		if(fen[i-1]+tz[i-1]>=fen[i-2]+tz[i-2])
			fen[i]=fen[i-1]+tz[i-1];
		else
			fen[i]=fen[i-2]+tz[i-2];
	}
	for(long long j=2;j<=n;j++)
		if(fen[j-1]>fen[j])
			fen[j]=fen[j-1];
	cout<<fen[n]%p;
	//system("pause");
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
