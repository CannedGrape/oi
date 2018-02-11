#include<iostream>
#include<cstdio>
#include<cstring>
#define RETURN_TYPE long
#define RT RETURN_TYPE
using namespace std;
RT* data,* num,n,i,j,* temp,*t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	RT p;
	cin>>n>>p;
	data=new RT[n];
	num=new RT[n];
	temp=new RT[n];
	t=new RT[n];
	memset(t,0,sizeof t);
	memset(data,0,sizeof data);
	memset(temp,0,sizeof temp);
	for (i=0;i<n;i++)
	{
		cin>>num[i];
		for (j=0;j<=i;j++)
			if (num[j]>0)
				data[i]+=num[j];
		if (data[i]==0)
		{
			data[i]=num[0];
			for (j=1;j<=i;j++)
				if (data[i]<num[j])
					data[i]=num[j];
		}
	}
	temp[0]=data[0];
	for (i=0;i<n;i++)
		t[i]=data[i]+num[i];
	for (i=1;i<n;i++)
	{
		temp[i]=t[0];
		for (j=1;j<i;j++)
			if (temp[i]<t[j])temp[i]=t[j];
	}
	for (i=1;i<n;i++)
		if (temp[0]<temp[i]) temp[0]=temp[i];
	
	if (temp[0]<0)
	{
		cout<<'-';
		temp[0]*=-1;
	}
	cout<<temp[0]%p;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
