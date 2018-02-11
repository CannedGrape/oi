#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int n,ans,k;
	srand((unsigned)time(NULL));
	scanf("%d",&n);
	k=n/2;
	ans=k-rand()%k+k;
	cout<<ans<<endl;
	return 0;
}
