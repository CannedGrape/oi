#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>

using namespace std;

const int Maxn=100010;
const int inf=99999999+413;

int n,ans;
int h[Maxn],q[Maxn];
int f[Maxn][2];
bool getans;

int get()
{
	int v=0,f=0; char ch;
	while(!isdigit(ch=getchar()));
	if(ch=='-') f=1; else v=ch-48;
	while(isdigit(ch=getchar())) v=v*10+ch-48;
	if(f) return -v; else return v;
}

void dfs(int k,int qn,int cut,int pro)
{
	if(getans) return;
	
	if(k==n+1)
	{
		getans=true; return;
	}
	else
	{
		if(qn==1)
		{
			q[qn]=h[k];
			dfs(k+1,qn+1,cut,1);
			dfs(k+1,qn+1,cut,-1);
			if(cut<ans) 
			{
				dfs(k+1,qn,cut+1,1);
				dfs(k+1,qn,cut+1,-1);
			}
		}
		else
		{
			if(pro==1)
			{
				if(qn%2==0)
				{
					if(h[k]>q[qn-1])
						q[qn]=h[k],dfs(k+1,qn+1,cut,1);
					if(cut<ans && !getans) dfs(k+1,qn,cut+1,1);
				}
				else
				{
					if(h[k]<q[qn-1])
						q[qn]=h[k],dfs(k+1,qn+1,cut,1);
					if(cut<ans && !getans) dfs(k+1,qn,cut+1,1);
				}
			}
			else
			{
				if(qn%2==0)
				{
					if(h[k]<q[qn-1])
						q[qn]=h[k],dfs(k+1,qn+1,cut,-1);
					if(cut<ans && !getans) dfs(k+1,qn,cut+1,-1);
				}
				else
				{
					if(h[k]>q[qn-1])
						q[qn]=h[k],dfs(k+1,qn+1,cut,-1);
					if(cut<ans && !getans) dfs(k+1,qn,cut+1,-1);
				}
			}
		}
	}
}

void work()
{
	for(int i=0;i<n;i++)
	{
		if(i==n-1) 
		{
			printf("%d\n",n-1);
			break;
		}
		getans=false; ans=i;
		dfs(1,1,0,0);
		if(getans)
		{
			printf("%d\n",n-ans);
			break;
		}
	}
}

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	
	n=get();
	for(int i=1;i<=n;i++) h[i]=get();
	if(n<=20) work();
	else
	{
		for(int i=2;i<=n;i++) f[i][0]=f[i][1]=inf;
	
		f[0][0]=f[0][1]=f[1][0]=f[1][1]=0;
		for(int i=2;i<=n;i++)
		{
			if(h[i]>h[i-1])
			{
				f[i][0]=f[i-1][1];
				f[i][1]=f[i-1][1]+1;
			}
			if(h[i]==h[i-1]) f[i][1]=f[i-1][1]+1,f[i][0]=f[i-1][0]+1;
			if(h[i]<h[i-1])
			{
				f[i][1]=f[i-1][0];
				f[i][0]=f[i-1][0]+1;
			}
		}
		
		ans=min(f[n][0],f[n][1]);
		printf("%d\n",n-ans);
	}
	
	//system("pause");
	return 0;
}

