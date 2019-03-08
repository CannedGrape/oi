#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m;
int s[1010],tk[1010][1010],a[1010];
int counts[1010]={0};
bool flag[1010][1010]={0};
bool cmp(int x,int y)
{   if (counts[x]>counts[y]) return true;
    else return false;
}
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	int i,j,tmp=0,ans=0;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{ scanf("%d",&s[i]);
	  for (j=1;j<=s[i];j++)
	  {scanf("%d",&tk[i][j]);
	   counts[tk[i][j]]++;
	   flag[tk[i][j]][i]=true;
	  }
	}
	for (i=1;i<=n;i++)
	{ a[i]=i;}
	sort(a+1,a+1+n,cmp);
	for (i=2;i<=n;i++)
	{ if (counts[a[i]]!=0)
	  { //cout<<counts[a[i]]<<' '<<m<<' '<<tmp<<' '<<ans<<endl;;
		if (counts[a[i]]==counts[a[1]]-tmp && counts[a[i-1]]==counts[a[1]]-tmp+1)
		{ans++;tmp++;}
	  }
	}
	ans++;
	cout<<ans<<endl;
	//if (m==2) cout<<"2"<<endl;
	//if (m==3) cout<<"3"<<endl;
	return 0;
}
