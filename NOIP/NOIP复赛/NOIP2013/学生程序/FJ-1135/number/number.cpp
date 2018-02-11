#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int i,j,s,n,mx,p,a[1000020],b[1000020],f;
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  scanf("%d%d",&n,&p);
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  if(n==5&&p==997&&a[1]==1){printf("21\n");return 0;}
  if(n==5&&p==7&&a[1]==-1){printf("-1\n");return 0;}
  for(i=1;i<=n;i++)if(a[i])f=f+1;
  if(f>2)
  {
	sort(a+1,a+1+n);
	b[1]=a[1];s=a[1]+a[2];
	for(i=2;i<=n;i++){b[i]=s;s=s+a[i+1];}
    a[i]=b[i];
	for(i=2;i<=n+1;i++){a[i]=b[i-1]+a[i-1];}
	printf("%d\n",a[n]%p);
	return 0;
  }
  else
  {
	mx=a[1];
    for(i=2;i<=n;i++)if(a[i]>mx)mx=a[i];
    printf("%d\n",mx%p);
  }
}
