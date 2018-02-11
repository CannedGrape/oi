#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int ss[1000005],tz[1000005],fs[1000005];
int n,p,fm,ans;
int fmax(int a,int b)
{
	if(a>b)return a;
	else return b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
	  cin>>ss[i];
	  if(i==1){tz[i]=ss[i];fs[i]=ss[i];fm=(tz[i]+fs[i])%p;}
	  else{tz[i]=fmax(tz[i-1]+ss[i],ss[i]);fs[i]=fm%p;fm=fmax(tz[i]+fs[i],fm)%p;}
	}
	sort(fs+1,fs+1+n);
	ans=fs[n];
	if(fs[n]<0){cout<<"-";ans*=-1;}
	ans%=p;
	cout<<ans<<endl;
	return 0;
}
