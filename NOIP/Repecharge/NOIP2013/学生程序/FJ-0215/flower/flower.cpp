#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MaxN=100001;

int f[MaxN][2],h[MaxN],n,ans=0;
int q0[MaxN][2],head0=0,tail0=-1;//short->tall 
int q1[MaxN][2],head1=0,tail1=-1;//tall->short

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&h[i]);
	}
	memset(f,0,sizeof(f));
	for (int i=0;i<n;i++)
	{
		f[i][0]=1;
		f[i][1]=1;
		
		for (int j=head0;j<=tail0;j++)
		{
			if (h[i]>q0[j][1])
			{
				f[i][0]=q0[j][0]+1;
				break;
			}
		}
		
		for (int j=head1;j<=tail1;j++)
		{
			if (h[i]<q1[j][1])
			{
				f[i][1]=q1[j][0]+1;
				break;
			}
		}
		
		ans=max(ans,max(f[i][0],f[i][1]));
		
		while (q0[tail0][0]<=f[i][1] && q0[tail0][1]>=h[i] && tail0>=0) tail0--;
		tail0++;
		int now=tail0;
		while ((q0[now-1][0]<f[i][1] || (q0[now-1][0]==f[i][1] && q0[now-1][1]>=h[i])) && now>=1)
		{
			q0[now][0]=q0[now-1][0];
			q0[now][1]=q0[now-1][1];
			now--;
		}
		q0[now][0]=f[i][1];
		q0[now][1]=h[i];
		
		while (q1[tail1][0]<=f[i][0] && q1[tail1][1]<=h[i] && tail1>=0) tail1--;
		tail1++;
		now=tail1;
		while ((q1[now-1][0]<f[i][0] || (q1[now-1][0]==f[i][0] && q1[now-1][1]<=h[i])) && now>=1)
		{
			q1[now][0]=q1[now-1][0];
			q1[now][1]=q1[now-1][1];
			now--;
		}
		q1[now][0]=f[i][0];
		q1[now][1]=h[i];
		
		//cout<<i<<' '<<f[i][0]<<' '<<f[i][1]<<endl;
	}
	printf("%d\n",ans);
	return 0;
}
