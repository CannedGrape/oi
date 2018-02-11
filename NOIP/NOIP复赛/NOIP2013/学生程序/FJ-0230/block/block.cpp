#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstring>
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
int n,a[101001],ans=0,le,ri,maxx=0,minn=10001,zuo,you,f[10101],ji=0;

void fen(int l,int r)
{
	int temp=0;
	{
		int small=10001;
		for(int j=l;j<=r;j++)
		{
			if(a[j]>small)small=a[j];	
		}
		for(int j=1;j<=n;j++)if(a[j]==0&&a[j-1]!=0)temp++;
		
		ans=ans+small*(temp-1);
		
		for(int j=1;j<=n;j++)if(a[j]>0)a[j]-=small;
	}
	return ;
}

int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		if(a[i]>maxx)maxx=a[i];
		if(a[i]<minn)minn=a[i];
	}
	ans=ans+minn;
	for(int i=1;i<=n;i++)a[i]=a[i]-minn;
	
	le=1;ri=n;
	for(int i=1;i<=n;i++)
		if(a[i]>0)
			fen(le,ri);
	cout<<ans<<endl;
	system("pause");
	return 0;
}
