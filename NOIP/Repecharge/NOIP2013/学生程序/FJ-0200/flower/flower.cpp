#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[100005],f[100005][2];
int q0[100005],q1[100005],tail0,tail1;
int get()
{
	int res=0,v=0;char ch;
	while (!isdigit(ch=getchar())) if (ch=='-')break;
	if (ch=='-') v=1;else res=ch-48;
	while (isdigit(ch=getchar())) res=res*10+ch-48;
	if (v) return -res;return res;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	int i,j,ans=1;
	for (i=1;i<=n;i++) a[i]=get();
	if (n<=2000)
	{
	  for (i=1;i<=n;i++)
	  {
		f[i][0]=1;f[i][1]=1;
	    for (j=1;j<i;j++)
	    {
		  if (a[j]>a[i]&&f[j][1]+1>f[i][0]) f[i][0]=f[j][1]+1;
		  if (a[j]<a[i]&&f[j][0]+1>f[i][1]) f[i][1]=f[j][0]+1;
	    }
	    ans=max(ans,max(f[i][0],f[i][1]));
	  }
	  printf("%d\n",ans);
	  return 0;
	}
	tail0=0;tail1=0;
	for (i=1;i<=n;i++)
	{
	  f[i][0]=f[i][1]=1;
	  while (tail0>0&&a[q0[tail0]]>a[i])
	  {
		f[i][0]=max(f[i][0],f[q0[tail0]][1]+1);
		tail0--;
	  }
	  while (tail0>0&&a[q0[tail0]]>=a[i]) tail0--;
	  q0[++tail0]=i;
	  while (tail1>0&&a[q1[tail1]]<a[i])
	  {
		f[i][1]=max(f[i][1],f[q1[tail1]][0]+1);
		tail1--;
	  }
	  while (tail1>0&&a[q1[tail1]]<=a[i]) tail1--;
	  q1[++tail1]=i;
	  ans=max(ans,max(f[i][0],f[i][1]));
	}
	printf("%d\n",ans);
	return 0;
}
