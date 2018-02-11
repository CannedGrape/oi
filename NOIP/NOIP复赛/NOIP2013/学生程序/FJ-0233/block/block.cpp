#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100001],minn,ans=0,n,m,minn1;
bool bo=false;
void shan()
{

	int i=1,j=1;
	minn=100000000;
	while (a[i]==0) i++;
	while (a[i]!=0)
	{
		if (minn>a[i])
		{
			minn=a[i];
			minn1=i;
		}
		i++;
	}
	//cout<<minn1<<"asdfasdasd"<<endl;
	//cout<<minn<<" "<<minn1;
	while (a[j]==0) j++;
	while (a[j]!=0)
	{
		a[j]=a[j]-minn;
        //cout<<a[j]<<endl;
        j++;
	}
	ans+=minn;
	/*for (int i=1; i<=n; i++)
	  cout<<a[i]<<" ";
	cout<<ans<<endl;
    */
}
int main()
{	freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin>>n;
	memset(a,0,sizeof(a));
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	while (true)
	{
		int p=0,q=1;
		while (a[q]==0)
		{
			p++;
			if (p==n)
		    {
				cout<<ans<<endl;
			    exit(0);
		    }
			q++;
		}
		//cout<<p<<endl;
	    shan();
	}
	return 0;
}
