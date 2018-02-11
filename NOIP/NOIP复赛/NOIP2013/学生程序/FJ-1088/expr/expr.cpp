#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring> 
#include <iostream>
#include <algorithm>
using namespace std;
char a[100001];
int b, j = 1, k = 2;
int c[100001] = {};
char d[100001] = {}; 
int main ()
{
	freopen("expr.in" ,"r", stdin);
	freopen("expr.out" ,"w", stdout);
	cin>>a;
	b = strlen(a);
	a[b]='m';
	for (int i = 0; i < b; i ++)
	{
		int n = i;
		if (a[i]!='*' && a[i]!='+' && a[i]!='m')
		{
			while(a[i]!='*' && a[i]!='+' && a[i]!='m')
				i++;		
			if(i-n >= 4)
				c[j] = a[i-1]-48+(a[i-2]-48)*10+(a[i-3]-48)*100+(a[i-4]-48)*1000;
			if(i-n == 3)
				c[j] = a[i-1]-48+(a[i-2]-48)*10+(a[i-3]-48)*100;
			if(i-n == 2)
				c[j] = a[i-1]-48+(a[i-2]-48)*10;
			if(i-n == 1)
				c[j] = a[i-1]-48;		
			j += 2;
			d[k] = a[i];
			k += 2;
		}
	}
	for (int i = 2; i < j; i ++)
	{
		if (d[i]=='*')
		{
			c[i-1] = (c[i-1]*c[i+1])%10000;
			for (int m = i+2; m < j; m++ ) { c[m-2]=c[m]; d[m-2]=d[m];}
			j -= 2;
			i --;
		}
	}
	for (int i = 2; i < j; i ++)
	{
		if (d[i]=='+')
		{
			c[i-1] = (c[i-1]+c[i+1])%10000;
			for (int m = i+2; m < j; m++ ) { c[m-2]=c[m]; d[m-2]=d[m];}
			j -= 2;
			i--;
		}
	}
	cout<<c[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
