#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
int get()
{
	int f=0,v=0;char ch;
	while(!isdigit(ch=getchar()))if(ch=='-')break;
	if(ch=='-')f=1;else v=ch-'0';
	while(isdigit(ch=getchar()))v=v*10+ch-'0';
	if(f==1)return -v;else return v;
}
const int maxn=100003;
int n,a[maxn],s[maxn],top=0,ans=0;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==s[top])continue;
		if(a[i]>s[top])
		{
			ans+=a[i]-s[top];
			s[++top]=a[i];
		}else
		{
			while(top&&s[top]>a[i])top--;
			s[++top]=a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
