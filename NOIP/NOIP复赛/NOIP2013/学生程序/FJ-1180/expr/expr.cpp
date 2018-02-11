#include<iostream> 
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
string s;
char fh[1000001];
int f,z,sz[1000001],sz1[1000001],z1=1,ans,k,y=1;
int main ()
{
	freopen ("expr.in","r",stdin);
	freopen ("expr.out","w",stdout);
	cin >>s;
	for (int b=s.size()-1;b>=0;--b)
	{
		if ((s[b]>='0') && (s[b]<='9') && (y<=4))
		{
			if (z==0)z=1;
			k=s[b]-'0';
			for (int b=1;b<=y;++b)k*=10;
			sz[z]+=k;y++;
		}
		if ((s[b]=='+')||(s[b]=='*'))
		{
			sz[z]/=10;
			z++;f++;y=1;
			fh[f]=s[b];
		}
	}sz[z]/=10;
	for (int b=z;b>=1;--b)
	{
		if ((fh[b]=='*'))sz1[z1-1]=sz[b]*sz1[z1-1]%10000;
		else {sz1[z1]=sz[b];z1++;}
	}
	for (int b=z1;b>=1;b-=2){ans+=sz1[b]+sz1[b-1];ans%=10000;}
	printf ("%d\n",ans);
	return 0;
}
