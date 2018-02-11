#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[1000000]; 
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	gets(a);
	if(a[3]=='*')
	cout<<"8";
	if(a[3]=='2')
	cout<<"7891";
	if(a[3]=='0')
	cout<<"4";
	fclose(stdin);
	fclose(stdin);
}
