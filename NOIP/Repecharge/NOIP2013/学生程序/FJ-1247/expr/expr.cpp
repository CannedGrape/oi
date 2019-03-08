#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stdlib.h>
using namespace std;
char a[1000000];
int main()
{
	int s=0,n,x=1,b=0,d=0;
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	gets(a);
	while(b<strlen(a))
	{
		if(d==0){d=1;n=atol(a);x=n;}
		while(a[b]!='+'&&a[b]!='*'&&b<strlen(a))
		{
			a[b]=' ';
			b++;
		}
		if(a[b]=='*'&&d==1)
		{
			a[b]=' ';
			n=atol(a);
			x=x*n;
		}
		else {s=s+x;x=1;d=0;}
		a[b]=' ';
		b++;
	}
	itoa(s,a,10);d=0;
	for(int i=strlen(a)-4;i<strlen(a);i++)
    if(a[i]!='0'||d==1){d=1;cout<<a[i];}
	fclose(stdin);
	fclose(stdout);
}
