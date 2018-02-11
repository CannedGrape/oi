#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstring>
#include<queue>
using namespace std;
inline void read(int &s)
{
	char ch;
	s=0;
	ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
}
int n,m,q,ans[3500][3500];
bool s[4000][4000];
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	//srand((unsigned)time(NULL));
	//int pd=rand()%2;
	memset(s,0,sizeof(s));
	memset(ans,210001,sizeof(ans));
	read(n);read(m);
	for(int i=1;i<=m;i++)
	{
		int xx,yy,zz;
		read(xx);read(yy);read(zz);
		ans[xx][yy]=zz;
		s[xx][yy]=true;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			if(!s[i][j]&&s[i][k]&&s[k][j])
			{
				s[i][j]=true;
				ans[i][j]=min(ans[i][k],ans[k][j]);
			}
	read(q);
	for(int i=1;i<=q;i++)
	{
		int xx,yy,temp;
		read(xx);read(yy);
			temp=ans[xx][yy];
		if(temp<200001)
			printf("%d\n",temp);
		else printf("-1\n");
	}
	cout<<endl;
	return 0;
}
