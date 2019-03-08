#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,x,i,a[10],s;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>x;
	for(i=1;i<=n;i++)
	  {
		int y=1;
		for(int j=0;j<10;j++)
		  a[j]=0;
		a[1]=i%10;
		if(i>=10)
		  {a[2]=(i%100)/10;y++;}
		if(i>=100)
		  {a[3]=(i%1000)/100;y++;}
		if(i>=1000)
		  {a[4]=(i%10000)/1000;y++;}
		if(i>=10000)
		  {a[5]=(i%100000)/10000;y++;}
		if(i>=100000)
		  {a[6]=(i%1000000)/100000;y++;}
		if(i>=1000000)
		  {a[7]=i/1000000;y++;}
		for(int j=1;j<=y;j++)
		  if(a[j]==x)
			s++;
	  }
	cout<<s<<endl;
	return 0;
} 

