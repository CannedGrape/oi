#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int n,mx;
bool find(int k)
{
	for(int i=2;i<=sqrt(k);i++)
		if(k%i==0) return 0;
	return 1;
}
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	cin>>n;
		for(int k=2;k<=sqrt(n);k++)
			if(n%k==0)
				if(find(k) && find(n/k) && k!=n/k)
					if(n/k>mx)
						mx=n/k;
	cout<<mx<<endl;
	fclose(stdout);
	return 0;
}
