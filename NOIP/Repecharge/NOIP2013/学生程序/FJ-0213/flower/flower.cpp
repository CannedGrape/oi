#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
int n,h1,h2,i,ans;
int a[100001];
bool p;
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	for (i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	i=1;
	while ((a[i]==a[i+1])and(i<n))i++;
	ans=1;
	i++;
	if (a[i]>a[i-1])p=true; else p=false;
	for (;i<=n;i++)
	{
		if ((p==true)and(a[i]<a[i-1])){p=false; ans++;} else 
		   if ((p==false)and(a[i]>a[i-1])){p=true; ans++;} 
	}
	ans++;
	cout<<ans<<endl;
	
}
/*
27
1 7 2 4 8 3 1 5 4 2 6 2 2 8 9 9 9 10 11 13 13 15 2 3 5 7 2
*/
