#include<iostream>
#include<cstdio>
using namespace std;
void lbl(int,int);
void zsh(int,int);
int a[1000001],b[1000001],c[1000001];
void lbl(int min,int max)
{
	int i,j,mid,temp;
	i=min;
	j=max;
	mid=c[(min+max)/2];
	do
	{
		while(c[i]<mid) i++;
		while(c[j]>mid) j--;
		if(i<=j)
		{
			temp=c[i];
			c[i]=c[j];
			c[j]=temp;
			i++;
			j--;
		}
	}while(i<=j);
	if(min<j) lbl(min,j);
	if(i<max) lbl(i,max);
}
int main()
{
	int n,max,i,j;long long p;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>p;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	lbl(1,n);
	b[1]=c[1];
	for(i=2;i<=n;i++) b[i]=c[i]+b[i-1];
	a[1]=b[1];
	a[2]=a[1]+b[1];
	for(i=3;i<=n;i++)
	{
		max=a[1]+b[1];
		for(j=2;j<=i-1;j++)
		{
			if(a[j]+b[j]>max)
			{
				max=a[j]+b[j];
			}
		}
		a[i]=max;
	}
	zsh(1,n);
	cout<<a[n]%p;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
void zsh(int min,int max)
{
	int i,j,mid,temp;
	i=min;
	j=max;
	mid=a[(min+max)/2];
	do
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}while(i<=j);
	if(min<j) zsh(min,j);
	if(i<max) zsh(i,max);
}
