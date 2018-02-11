#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
struct node
{int x;int y;};
node a[1000001],b[1000001];
void sort1(int l,int r)
{
	int i,j,x,y;
	i=l;j=r;x=a[(l+r)/2].x;
    while(i<=j)
    {
		while (a[i].x<x)i++;
        while (x<a[j].x)j--;
        if (i<=j)
        {
			y=a[i].x; a[i].x=a[j].x; a[j].x=y;
            y=a[i].y; a[i].y=a[j].y; a[j].y=y;
            i++;j--;
        }
    }
    if (l<j)sort1(l,j);if (i<r)sort1(i,r);
}
void sort2(int l,int r)
{
	int i,j,x,y;
	i=l;j=r;x=b[(l+r)/2].x;
    while(i<=j)
    {
		while (b[i].x<x)i++;
        while (x<b[j].x)j--;
        if (i<=j)
        {
			y=b[i].x;b[i].x=b[j].x;b[j].x=y;
            y=b[i].y;b[i].y=b[j].y;b[j].y=y;
            i++;j--;
        }
    }
    if (l<j)sort2(l,j);if (i<r)sort2(i,r);
}
int n;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	  {cin>>a[i].x;a[i].y=i;}
	for(int i=1;i<=n;i++)
	  {cin>>b[i].x;b[i].y=i;}
	sort1(1,n);
	sort2(1,n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=ans+abs(a[i].y-b[i].y)%99999997;
		if(a[i].y<=b[i].y)
		{
			a[i].y=b[i].y;
		  for(int j=a[i].y+1;j<=b[i].y;j++)
		    {
				for(int q=1;q<=n;q++)
				  {if (a[q].y==i)a[q].y--;continue;}
			}
	   }
		else
		{
			a[i].y=b[i].y;
		  for(int j=b[i].y;j<a[i].y;j++)
		    {
				for(int q=1;q<=n;q++)
				  {if (b[q].y==i)b[q].y++;continue;}
			}
	   }	
	}
	cout<<ans;
	return 0;
} 
