#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int n,x,i;
long long ans=0;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>x;
	for(i=1;i<=n;i++)ans+=((i/1000000==x)+(i%1000000/100000==x)+(i%100000/10000==x)+(i%10000/1000==x)+(i%1000/100==x)+(i%100/10==x)+(i%10==x));
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	//system("pause");
	return 0;
}
