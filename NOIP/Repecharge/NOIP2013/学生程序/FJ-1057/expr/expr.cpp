#include<iostream>
#include<cstdio>
#define RETURN_TYPE unsigned short
#define RT RETURN_TYPE
using namespace std;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	
	char temp;
	RT data[4][5]={},len[3]={},rear[3]={},sign=1,i,j;
	while(!cin.eof())
	{
		temp=getchar();
		for (i=0;i<5;i++) data[sign][i]=0;
		while(temp=='0') temp=getchar();//DETELE '0'
		len[sign]=0;
		while(temp!='+'&&temp!='*'&&cin.eof()==0&&temp!='\n')
		{
			data[sign][rear[sign]++]=temp-'0';
			rear[sign]%=5;
			if (len[sign]<4)len[sign]++;
			temp=getchar();
		}
		if (cin.eof()) temp='+';
		while (rear[sign]!=0)
		{
			for (i=(rear[sign]+1)%5;i!=rear[sign];i=(i+1)%5)
				data[sign][i]=data[sign][(i+1)%5];
			rear[sign]--;
		}
		for (i=4-len[sign];i!=65535;i--)
			data[sign][i]=0;
		if (sign==2)
		{
			for (i=0;i<5;i++) data[3][i]=0;
			for (i=4-len[sign];i!=65535;i--)
				data[sign][i]=0;
			for (i=4;i>0;i--)
				for (j=4;j>0;j--)
					if (i+j-4>0)
						data[3][i+j-4]+=data[sign][i]*data[sign-1][j];
			sign=2;
			for (i=4;i>0;i--) data[sign][i]=data[sign+1][i];
			for (i=4;i>0;i--)
			{
				data[sign][i-1]+=data[sign][i]/10;
				data[sign][i]%=10;
			}
		}
		if (temp=='+') sign=1;
		else sign=2;
		if (sign==1)
		{
			for (i=4;i>0;i--)
			{
				data[sign-1][i]+=data[sign][i];
				data[sign-1][i-1]+=data[sign-1][i]/10;
				data[sign-1][i]%=10;
			}
		}
	}
	for (i=1;i<5&&data[0][i]==0;i++);//DELETE '0'
	if (i==5) cout<<0;
	for (;i<5;i++)	cout<<data[0][i];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
