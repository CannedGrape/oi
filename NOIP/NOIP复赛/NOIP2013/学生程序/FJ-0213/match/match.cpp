#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
struct node1
{
	int num,pos;
};
node1 a[1001],b[1001],swap1;
struct node2
{
	int pos1,pos2;
};
node2 c[1001],swap2;
int f[1001];
int n,i,j,ans=0;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a[i].num;
		a[i].pos=i;
	}
	for (i=1;i<=n;i++)
	{
		cin>>b[i].num;
		b[i].pos=i;
	}
	for (i=1;i<=n-1;i++)
	    for (j=i+1;j<=n;j++)
		    if (a[i].num>a[j].num)
			{
				swap1=a[i]; a[i]=a[j]; a[j]=swap1;
			}
	//for (i=1;i<=n;i++)cout<<b[i].num<<' '<<b[i].pos<<endl;
	for (i=1;i<=n-1;i++)
	    for (j=i+1;j<=n;j++)
		    if (b[i].num>b[j].num)
		    {
				swap1=b[i]; b[i]=b[j]; b[j]=swap1;
			}
	//for (i=1;i<=n;i++)cout<<b[i].num<<' '<<b[i].pos<<endl;
	for (i=1;i<=n;i++)
	{
		c[i].pos1=a[i].pos;
		c[i].pos2=b[i].pos;
		//cout<<c[i].pos1<<' '<<c[i].pos2<<endl;
	}
	for (i=1;i<=n-1;i++)
	    for (j=i+1;j<=n;j++)
	        if (c[i].pos1>c[j].pos1)
	        {
				swap2=c[i]; c[i]=c[j]; c[j]=swap2;
			}
	for (i=1;i<=n;i++)f[i]=c[i].pos2;
	//for (i=1;i<=n;i++)cout<<f[i]<<' ';		
	for (i=1;i<=n;i++)
	{
		int pos;
		for (j=i;j<=n;j++)if (f[j]==i){pos=j; break;}
		ans+=pos-i; ans%=99999997;
		for (j=pos;j>=i+1;j--)f[j]=f[j-1];
		//for (j=1;j<=n;j++)cout<<f[j]<<' ';
		//cout<<endl;
	}			   	
	cout<<ans;
} 
/*
4
1 3 4 2 
1 7 2 4
6
1 2 3 4 5 6
5 6 2 3 4 1
6
2 4 5 7 15 6 
3 2 7 6 5 10  
*/
