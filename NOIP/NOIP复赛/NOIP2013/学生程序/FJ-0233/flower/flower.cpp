#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
using namespace std;
int b[1000001],a[1000001],n,m,ans,maxx=0,minn=10000000,p1,q1,p2,q2;
int b1=1,b2=1,ans1=3,ans2=3;
int main()
{
	freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for (int i=2; i<=n-1; i++)
	{
		if (maxx<a[i])
		{
			maxx=a[i];
			p1=i-1;
			p2=i+1;
		}
        if (minn>a[i]) 
		{
			minn=a[i];
			q1=i-1;
			q2=i+1;
		}
	}
	int p=p1,q=q1;
	while (p1>1)
	{
		p1--;
		if (b1%2!=0) if (a[p1]>a[p]){ a[p]=a[p1]; ans1++; b1++; }			 
		if (b1%2==0) if (a[p1]<a[p]){ a[p]=a[p1]; ans1++; b1++; }
	} 
	b1=1;
	int p3=p2,q3=q2;
	while (p2<n)
	{
		p2++;
		if (b1%2!=0) if (a[p2]>a[p3]){ a[p3]=a[p1]; ans1++; b1++; }			 
		if (b1%2==0) if (a[p2]<a[p3]){ a[p3]=a[p1]; ans1++; b1++; }
	}
	while (q1>1)
	{
		q1--;
		if (b2%2!=0) if (a[q1]<a[q]){ a[q]=a[q1]; ans2++; b2++; }			 
		if (b2%2==0) if (a[q1]>a[q]){ a[q]=a[q1]; ans2++; b2++; }
	} 
	b2=1;
	while (q2<n)
	{
		q2++;
		if (b2%2!=0) if (a[q2]<a[q3]){ a[q3]=a[q1]; ans2++; b2++; }			 
		if (b2%2==0) if (a[q2]>a[q3]){ a[q3]=a[q1]; ans2++; b2++; }
	}
	//cout<<ans1<<" "<<ans2<<endl;
	if (ans1>ans2) cout<<ans1<<endl;
	else cout<<ans2<<endl;
	return 0;
}
