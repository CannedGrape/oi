#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[1001]={0},minn=0,n=0,m=0;
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
	  int h,k;
	  cin >> h;
	  for(int j=1;j<=h;j++){cin >> k;a[k]++;}
    }
    for(int i=1;i<=n;i++)
    {
		int y=0;
		for(int j=1;j<=n;j++)
		  if(a[j]==i)y++;
		if(minn==0)minn=i;
	    if(y<minn)minn=i;
	}
	cout << minn << endl;
	return 0;
}
