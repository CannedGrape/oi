#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,k,ans=0;
struct km
{
 int v,pos; 
};
km a[100000],b[100000];
int POS[100000];
bool cmp(km x,km y)
{
 if(x.v!=y.v) return x.v<y.v;
 else return x.pos<y.pos;	
}
int main()
{
 freopen("match.in","r",stdin);
 freopen("match.out","w",stdout);	
 scanf("%d",&n);
 for(int i=1; i<=n; i++) 
 {
  scanf("%d",&a[i].v);
  a[i].pos=i;
 }	
 for(int i=1; i<=n; i++) 
 {
  scanf("%d",&b[i].v);
  b[i].pos=i;	
 }
 sort(a+1,a+n+1,cmp);
 sort(b+1,b+n+1,cmp);
 for(int i=1; i<=n; i++) POS[b[i].pos]=i;
 for(int i=1; i<=n; i++)
 {
  if(a[i].pos!=b[i].pos)	
  {
	if(b[i].v!=b[POS[a[i].pos]].v) ans++;
	if(ans>99999997) ans-=99999997;	
	int tpos=b[POS[a[i].pos]].pos;
	int tv=b[POS[a[i].pos]].v;	
	b[POS[a[i].pos]].pos=b[i].pos;
	b[POS[a[i].pos]].v=b[i].v;	
	b[i].pos=tpos;
	b[i].v=tv;
  }	
 }
 printf("%d\n",ans);
 return 0;
}
