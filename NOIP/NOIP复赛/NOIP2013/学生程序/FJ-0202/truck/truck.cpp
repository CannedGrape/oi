#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstring>
using namespace std;
struct qq{int e,d,n;}v[100009];
int h[10009],f,m,a,b,c,mm=-214768,q,mi,l,r,an;
bool hh[10009];
int mmin(int a,int b){if(a<b)return a;return b;}
inline int qq1(int q,int e,int j,int k)
{   v[q].n=h[e];	
	h[e]=q;
	v[q].e=j;
	v[q].d=k;
	return 0;}
bool qq3(int q,int z)	
{   bool y=0; 
	if(q==z)return 1;
	hh[q]=0;
	for(int i=h[q];i;i=v[i].n)
      if((v[i].d>=mi)&&(hh[v[i].e]))
     	if(qq3(v[i].e,z))y=1;
    hh[q]=1; 	
	return y;
}
int main()
{	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>f>>m;
	memset(h,0,sizeof(h));memset(v,0,sizeof(v));
	for(int i=1;i<=m;i++)
	{cin>>a>>b>>c;if(c>mm)mm=c;
	 qq1(2*i-1,a,b,c);
	 qq1(2*i,b,a,c);}
	cin>>q;	
	for(int i=1;i<=q;i++)
	{ cin>>a>>b;
	  memset(hh,1,sizeof(hh));
	  r=mm;an=-1;l=0;
	  while((l<=r)&&(r>0))
	  {mi=(l+r+1)/2;
	   if(qq3(a,b)){an=mi;l=mi+1;}
	        else r=mi-1;
	} cout<<an<<endl; }	
  return 0;
}

