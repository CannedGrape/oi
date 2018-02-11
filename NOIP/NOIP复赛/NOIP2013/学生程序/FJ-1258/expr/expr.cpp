#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a,b=0,c[100]={0},d[100]={0},c1=0,d1=0,c2=0,d2=0,aq=0,aq2=0;;
char a2[10000],a1[10000];
long a4=0;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	gets(a2);
	a=strlen(a2);
	for(int i=0;i<a;i++)
	{
		if(a2[i]=='*')
		{c[c1]=i+1;c1++;}
		if(a2[i]=='+')
		{d[d1]=i+1;d1++;}
	}
	for(int i=0;i<a/2;i++)
	{
		if(i-1!=-1&&c[0]>d[0])
		{
		for(int j=c[i-1]+1;j<c[i];j++)
		{
			a1[c2]=a2[j];
			c2++;
		}
		c2=0;
		itoa(aq,a1,10); 
		for(int k=0;k<a/2;k++)a1[i]='\0';
		for(int j1=c[i]+1;j1<c[i+1];j1++)
		{
			a1[c2]=a2[j1];
			c2++;
		}
		c2=0;
		itoa(aq2,a1,10);
		a4=a4+aq*aq2;
		aq=0;
		aq2=0;
		for(int k=0;k<a/2;k++)a1[i]='\0';
	    }
	    else
	   { for(int j=0;j<c[i];j++)
		{
			a1[c2]=a2[j];
			c2++;
		}
		itoa(aq,a1,10);
		c2=0;
		for(int k=0;k<a/2;k++)a1[i]='\0';
		for(int j1=c[i]+1;j1<c[i+1];j1++)
		{
			a1[c2]=a2[j1];
			c2++;
		}
		c2=0;
		itoa(aq2,a1,10);
		a4+=aq*aq2;
		aq=0;
		aq2=0;
		for(int k=0;k<a/2;k++)a1[i]='\0';
	    }
	}
	for(int i=0;i<a;i++)
	{
		if(i!=0&&d[0]>c[0])
		{for(int j=d[i-1]+1;j<d[i];j++)
		{
			a1[d2]=a2[j];
			d2++;
		}
		d2=0;
		itoa(aq,a1,10);
		aq=0;
		aq2=0;
		for(int k=0;k<a/2;k++)a1[i]='\0';
		for(int j1=d[i]+2;j1<d[i+1];j1++)
		{
			a1[d2]=a2[j1];
			d2++;
		}
		d2=0;
		itoa(aq2,a1,10);
		a4+=aq+aq2;
		aq=0;
		aq2=0;
	    }
	    else
	    {for(int j=0;j<d[i];j++)
		{
			a1[d2]=a2[j];
			d2++;
		}
		d2=0;
		itoa(aq,a1,10);
		aq=0;
		aq2=0;
		for(int k=0;k<a/2;k++)a1[i]='\0';
		for(int j1=d[i]+1;j1<d[i+1];j1++)
		{
			a1[d2]=a2[j1];
			d2++;
		}
		d2=0;
		itoa(aq2,a1,10);
		a4+=aq+aq2;
		aq=0;
		aq2=0;
	    }
	}
	cout<<a4;
	fclose(stdin);
	fclose(stdout);
}
