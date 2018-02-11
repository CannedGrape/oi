#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
struct xx{
  int pos;
  long long x;
}a[100001],b[100001];
int n,x1[100001],y1[100001],ans;
bool p[100001];
bool cmp(xx l,xx r)
{
	return(l.x<r.x);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i].x),a[i].pos=i;
	for (int i=1;i<=n;i++) scanf("%lld",&b[i].x),b[i].pos=i;
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	memset(p,false,sizeof(p));
	for (int i=1;i<=n;i++)
	{
      x1[a[i].pos]=i;
	  y1[b[i].pos]=i;    
	}
	for (int i=1;i<=n;i++)
	 if (!p[y1[i]])
	 {
	    p[y1[i]]=true;
	    if (x1[i]==y1[i]) continue;
	    int s=y1[i],k=0,q;
	    while (x1[i]!=s)
	     {
			q=a[s].pos;
			s=y1[a[s].pos];
			p[s]=true;	
		 }
	  k=abs(q-a[i].pos);
	  ans=(ans+k)%99999997;	 
	 }
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
}
