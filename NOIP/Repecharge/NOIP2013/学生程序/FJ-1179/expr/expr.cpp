#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
string str1;
int l,sl,li;
int a[100002];
void getnumber(int g)
{
    int i;
	for(i=g;i<l;i++)
    {
	  if(str1[i]=='*' || str1[i]=='+')break;
	  a[sl+1]=(a[sl+1]*10+(str1[i]-48))%10000;
	}
	li=i-1;
}
void getss()
{
    l=str1.size();
    for(li=0;li<l;li++)
    {
	  if(str1[li]=='*')
	  {
	    sl++;
		getnumber(li+1);
		a[sl]=(a[sl]*a[sl+1])%10000;
		a[sl+1]=0;
		sl--;
	  }
	  else if(str1[li]=='+')sl++;
	       else getnumber(li);
	}
	for(int i=2;i<=sl+1;i++) a[1]=(a[1]+a[i])%10000;
}
int main()
{
    freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin >>str1;
    getss();
    printf("%d",a[1]);
    return 0;
}