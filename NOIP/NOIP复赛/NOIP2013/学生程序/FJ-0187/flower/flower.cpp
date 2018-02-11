#include <iostream>
#include <cstdio>
using namespace std;
int n,h[100005];
int main()
{	
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	bool d1=0,d2=0;
	int ans1=0,ans2=0,ans,t;
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	scanf("%d",&h[i]);
	for(i=2;i<=n;i++)
	{if(h[i]>h[i-1] && d1==0) {ans1++,d1=1,d2=0;}
	if(h[i]<h[i-1] && d2==0) {ans2++,d2=1,d1=0;}}
	ans1=ans1*2+1;
	ans2=ans2*2+1;
	 t=n;
	 while(h[t]==h[t-1])
	 {t--;}
	 if(h[t]>h[t-1]) ans1--;
	 if(h[t]<h[t-1]) ans2--;
	if(ans1>ans2) ans=ans1;
	else ans=ans2;
	cout<<ans;
	return 0;
}
