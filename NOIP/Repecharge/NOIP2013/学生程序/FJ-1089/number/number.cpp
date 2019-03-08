#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int num[1000001][2]={0},i,j,n,m,s[1000001];
int sum_(int k)
{
	int ans=0;
	for(j=1;j<=k;j++)ans+=num[j][0];
		return ans;
}
int qz(int p)
{
	s[1]=num[1][2];
	int max_=-9999999;
	for(j=2;j<=p+1;j++)s[j]=num[j-1][1]+num[j-1][2];
	for(j=1;j<=p;j++)
		if(s[j]>max_)max_=s[j];
			return max_;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int max_a=-9999999;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>num[i][0];
	for(i=1;i<=n;i++)num[i][1]=sum_(i);
		num[1][2]=num[1][1];
	for(i=2;i<=n;i++)num[i][2]=qz(i); 
	for(i=1;i<=n;i++)
		 if(num[i][2]>max_a)max_a=num[i][2];
	cout<<abs(max_a)/max_a*(abs(max_a)%m);
	fclose(stdin);
	fclose(stdout);
	//system("pause");
	return 0;
}