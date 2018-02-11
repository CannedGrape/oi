#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#define LL long long
using namespace std;
LL N,M,K,X;
LL KSM()
{
	LL k=K;
	LL cs=10%N;
	LL ans=1;
	while (k)
	{
		if (k&1) ans=(ans%N)*(cs%N)%N;
		cs=(cs%N)*(cs%N)%N;
	    k>>=1;
    }
    return ans;
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin>>N>>M>>K>>X;
	LL k10=KSM();
	LL ans=(M%N)*(k10%N)%N;
	ans=((ans%N)+(X%N))%N;
	cout<<ans<<endl;
	return 0;
}
