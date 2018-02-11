#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int last;int next;int data;
};
node a[100001];
int n;
bool pd(int i)
{
	if((i==1)||(i==n)) return true;
	if(((a[i].data>a[a[i].last].data)&&(a[i].data>a[a[i].next].data))||((a[i].data<a[a[i].last].data)&&(a[i].data<a[a[i].next].data)))return true;
	return false;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].data;
		a[i].next=i+1;
		a[i].last=i-1;
	}
	int m=n;
	for(int i=1;i<=n;i++)
	{
		if (!pd(i)){
		m--;
		a[a[i].last].next=a[i].next;
		a[a[i].next].last=a[i].last;}
	}
	cout<<m;
	return 0;
}
