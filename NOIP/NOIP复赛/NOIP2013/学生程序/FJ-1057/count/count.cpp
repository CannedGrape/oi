#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#define RETURN_TYPE unsigned long
#define RT RETURN_TYPE
using namespace std;
RT temp[]={1,10,100,1000,10000,100000,1000000,1000000};
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	RT n,x,i=0,j=0,k;
	cin>>n>>x;
	RT data[n+1],total=0;
	memset(data,0,sizeof data);
	while(i<=n)
	{
		if (i>9)
		{
			data[i]=data[i%temp[j]];
			k=1;
			while (x==0&&i%temp[j]<temp[j-k]&&j-(k++)!=0)
				data[i]++;
		}
		if (i/temp[j]==x) data[i]++;
		total+=data[i];
		if (++i==temp[j+1])j++;
	}
	cout<<total;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//NOTE:USING DP
//WRONG:WHEN X==0 SOLVED