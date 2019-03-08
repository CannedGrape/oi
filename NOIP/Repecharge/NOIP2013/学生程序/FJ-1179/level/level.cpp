#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
    int s[1001],x;
}a[1001];
int n,m,ans;
int lv[1001],fl[1001];
int main()
{
    freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
	  scanf("%d",&a[i].x);
	  for(int j=1;j<=a[i].x;j++)
	    scanf("%d",&a[i].s[j]);
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=a[i].x;j++)
	    lv[a[i].s[j]]++;
	for(int i=1;i<=n;i++)
	  if(lv[i]>0 && fl[lv[i]]==0)ans++,fl[lv[i]]=1;
	printf("%d",ans);
	return 0;
    
}