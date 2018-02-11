#include <iostream>
#include <cstdio>
using namespace std;
int ans,n,m,a[10005][10005]={0},q,g[10005][10005],l[10005]={0},v[10005],b,ans1[10005][10005];
bool d=0;
bool bfs(int x,int y,int z)
{
	int i,temp;
	if(x==y) {ans=max(ans,z);d=1;return 1;}
	for(i=1;i<=l[x];i++)
    {temp=min(z,a[x][g[x][i]]);if(temp>v[g[x][i]] && g[x][i]!=b)  v[g[x][i]]=temp,bfs(g[x][i],y,temp);}
    if(d==1) return 1;
    else return 0;
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	int i,x,y,z;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	ans1[i][j]=100000001;
	for(i=1;i<=m;i++)
	{
	scanf("%d%d%d",&x,&y,&z);
	if(z>a[x][y]) 
	{
	if(a[x][y]==0) l[x]++,l[y]++;
	 g[x][l[x]]=y;g[y][l[y]]=x;
	 a[x][y]=a[y][x]=z;
	}
	}
	
	cin>>q;
	for(i=1;i<=q;i++)
	{
	cin>>x>>y;
	if(x>n || y>n || x<=0 || y<=0) cout<<-1<<endl;
	else {
		if(ans1[x][y]!=100000001) cout<<ans1[x][y]<<endl;
		else 
		{d=0;
		 b=x;
	     ans=0;
	     for(int j=1;j<=n;j++)  v[j]=0;
		 if(bfs(x,y,100000001)) {cout<<ans<<endl,ans1[x][y]=ans1[y][x]=ans;}
         else {cout<<-1<<endl,ans1[x][y]=ans1[y][x]=-1;}
		}
	}
	}
    return 0;
}
