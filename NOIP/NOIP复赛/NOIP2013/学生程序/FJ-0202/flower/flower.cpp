#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n,h[100009],s=1,u,t;
bool q=0;
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)cin>>h[i];
	u=h[0];q=1;t=1;
	while(t<n)
	{	while((t<n)&&(u>=h[t])){u=h[t];t++;	}
	    if(t==1)s--;
		s++;
		if(t>=n)break;
		while((t<n)&&(u<=h[t])){u=h[t];t++;	}
		s++;}
	cout<<s;	
	return 0;
}
