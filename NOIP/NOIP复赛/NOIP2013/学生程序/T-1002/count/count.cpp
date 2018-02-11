#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,x,i,j,sum=0;
	cin>>n>>x;
	for(j=1;j<=n;j++)
	{
	  i=j;
	  while(i>0)
	 {
      if(i%10==x)sum++;
	  i/=10;	
	 }
	}
	cout<<sum<<endl;
	return 0;
}
