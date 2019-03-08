#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int N = 100001;
int h[N],nt[N],n,k=0;
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		nt[i]=i+1;
	}
	for (int i=1;nt[nt[i]]<=n;)
	 if (h[i]<=h[nt[i]] && h[nt[i]]<=h[nt[nt[i]]]
	  || h[i]>=h[nt[i]] && h[nt[i]]>=h[nt[nt[i]]]) k++,nt[i]=nt[nt[i]];
	 else i=nt[i];
	cout << n-k << endl;
	return 0;
}

