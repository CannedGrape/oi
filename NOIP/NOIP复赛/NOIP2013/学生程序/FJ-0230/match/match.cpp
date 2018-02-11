#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
	int wei,zhi,dui,hao;
	bool operator <(const node &t)
	const
	{
		return t.zhi>zhi;
	}
}a[100001],b[100001];
priority_queue<node>qa;
priority_queue<node>qb;

int n,ans=0;
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
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(n);
	
	for(int i=1;i<=n;i++)
	{
		read(a[i].zhi);a[i].wei=a[i].hao=i;
		qa.push(a[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		read(b[i].zhi);b[i].wei=b[i].hao=i;
		qb.push(b[i]);
	}
	
	while(!qa.empty())
	{
		node s1,s2;
		s1=qa.top();s2=qb.top();
		a[s1.hao].dui=s2.hao;
		b[s2.hao].dui=s1.hao;
		qa.pop();qb.pop();
	}
	for(int i=1;i<=n;i++)
	{
		int temp=a[i].wei-b[a[i].dui].wei;
		if(temp<0)
			for(int j=1;j<=n;j++)
				if(a[j].wei>a[i].wei&&a[j].wei<b[a[i].dui].wei)a[j].wei--;
		else 
			for(int j=1;j<=n;j++)
				if(a[j].wei>b[a[i].dui].wei&&a[j].wei<a[i].wei)a[j].wei++;
		ans+=abs(temp);
	}
	cout<<ans-1<<endl;
	return 0;
}
