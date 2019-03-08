#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int maxx(int i,int j)
{
	if(i>=j)return i;
	else return j;
}
int minn(int i,int j)
{
	if (i>=j) return j;
	else return i;
}
int a[110001],i,j,k,m,n,l,r,f1[110001]={0},f2[110001]={0},l2=1;
int main()
{
	cin>>n;f1[0]=214748314;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	l=1;
	for(i=1;i<=n;i++)
	{
		//if(i%2==0)f1[i]=maxx(f2[i-1],a[i]);
		//else f1[i]=minn(f2[i-1],a[i]);
		if(l%2==0)
		{
			if(f1[l-1]<a[i]&&f1[i-1]>a[i-2]) {f1[l]=a[i];l++;}
			else f1[l]=f1[l-1];
			}
			else {
				if(f1[l-1]>a[i]&&f1[i-1]>a[i-2]) {f1[l]=a[i];l++;}
			else f1[l]=f1[l-1];
			}
		}
	for(i=1;i<=n;i++)
	{
		//if(i%2==0)f2[i]=minn(f2[i-1],a[i]);
		//else f2[i]=maxx(f2[i-1],a[i]);
		if(l2%2==0)
		{
			if((f2[l2-1]>a[i]&&(f2[i-1]>a[i-2]&&i>2))||(f2[l2-1]>a[i]&&i<=2)) {f2[l2]=a[i];l2++;}
			else f2[l2]=f2[l2-1];
			}
			else 
			{
				if((f2[l2-1]<a[i]&&(f2[i-1]<a[i-2]&&i>2))||(f2[l2-1]<a[i]&&i<=2)) {f2[l2]=a[i];l2++;}
			else f2[l2]=f2[l2-1];
			}
			}
		for(i=1;i<=n;i++)cout<<f1[i]<<" ";cout<<endl;
		for(i=1;i<=n;i++)cout<<f2[i]<<" ";
		cout<<endl<<l<<" "<<l2;
		return 0;	
}
 
