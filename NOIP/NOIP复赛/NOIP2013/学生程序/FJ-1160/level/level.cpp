#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,ans[1001];

int main()
{
	freopen("level.in","r",stdin);freopen("level.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int s;m--;)
	{
	  scanf("%d",&s);
	  int t[1001];
	  for(int i=1;i<=s;++i) scanf("%d",t+i);
	  int y=ans[t[1]]>ans[t[s]]?ans[t[1]]:ans[t[s]];
	  for(int i=1;i<s;++i) for(int j=t[i]+1;j<t[i+1];++j) if(ans[j]<=y) ans[j]=y+1;
	}
	printf("%d",*max_element(ans+1,ans+n+1)+1);
	return 0;
}
