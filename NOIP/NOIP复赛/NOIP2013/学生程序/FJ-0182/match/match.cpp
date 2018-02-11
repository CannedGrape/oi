#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct node
{
	int x,I;
	bool operator<(const node a1)const{return a1.x>x;}
};
struct node ax[100001],ay[10001];
int n,bx[100001],by[100001],cx[100001],cy[100001];
bool FL[100001];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>ax[i].x;ax[i].I=i;bx[i]=ax[i].x;}
	for(int i=1;i<=n;i++){cin>>ay[i].x;ay[i].I=i;by[i]=ay[i].x;}
	sort(ax+1,ax+n+1);
	sort(ay+1,ay+n+1);
	for(int i=1;i<=n;i++){cx[ax[i].I]=ay[i].I;cy[ay[i].I]=ax[i].I;}
	int ans=0,k=1;
	bool FL;
	do
	{
		FL=false;
		for(int i=1;i<=n-k;i++)if(cx[i]>cx[i+1]){ans=ans+1;int y=cx[i];cx[i]=cx[i+1];cx[i+1]=y;FL=true;}
		while(ans>99999997)ans-=99999997;
	}
	while(FL);
	cout<<ans;
	return 0;
}

