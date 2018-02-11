#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	char a,b,c,d;
	int q,w,e,r,t;
	cin>>q>>a>>w>>b>>e>>c>>r>>d>>t;
	cout<<q+w*e*r+t;
} 
