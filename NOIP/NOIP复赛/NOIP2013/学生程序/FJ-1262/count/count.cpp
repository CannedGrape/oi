#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int main()
{
 int n,x,g=0;
 freopen("count.in","r",stdin);
freopen("count.out","w",stdout);
 cin>>n>>x;
 for(int i=1;i<=n;i++)
 {
	if(i%10==x||(i/10)==x||(i/100)==x||(i/1000)==x||(i/10000)==x||(i/100000)==x||(i/1000000)==x)
	{
		g++;
	}
	if(i==x*10+x)
	{
	g++;
	}
 }
cout<<g;
fclose(stdin);
fclose(stdout);
}

