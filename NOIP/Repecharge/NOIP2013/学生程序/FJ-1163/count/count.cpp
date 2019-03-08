#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,x;
	
	int no=0;
	cin>>n>>x;
	int i,j;
	for(i=1;i<=n;i++)
	{
		j=i;
		while(j>0)
		{
		if(j%10==x)no++;
		j=j/10;
	    }
	    
	    
	}
	cout<<no;
	return 0;
}
