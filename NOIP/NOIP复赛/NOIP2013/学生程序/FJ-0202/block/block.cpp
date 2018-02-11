#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct qq{int l,r,m;}f[200009];
int n,k,h,s=0,a[100009],o;
bool rr[100009];
int mmax(int a,int b){if(a>b)return a;return b;}
int mmin(int a,int b){if(a<b)return a;return b;}
/*int tt(int q,int l,int r)
{   int x,y;
	if(l==r){f[q].l=f[q].r=l;f[q].m=a[l];return a[l];}
	f[q].l=l;f[q].r=r;
	x=tt(2*q,l,(l+r)/2);y=tt(2*q+1,(l+r)/2+1,r);
	f[q].m=mmax(x,y);
	return f[q].m;}
int cc(int q)	
{	if(f[q].l==0)return 0;
	if(f[q].m==0){if(rr[f[q].r+1])s++;return 0;}
	f[q].m--;
    if(f[q].l==f[q].r)return 0;  
    int mid=(f[q].l+f[q].r)/2;    
	cc(q*2);
	if(f[2*q+1].m)cc(q*2+1);
	return 0;}
int ff(int q)
{   
	if(f[q].m==0){
     	for(int i=f[q].l;i<=f[q].r)
	     rr[i]=0;return 0;}
	if(f[q].l==f[q].r)return 0;
	if(f[2*q+1].m==0){rr[(f[q].l+f[q].r)/2+1]=0;}
	ff(2*q+1);return 0;}	
int ts()
{
	for(int i=1;i<10;i++)cout<<rr[i]<<' ';cout<<endl<<endl;
    for(int i=1;i<=2*n;i++)cout<<i<<' '<<f[i].l<<' '<<f[i].r<<' '<<f[i].m<<endl;cout<<endl;
    cout<<"s="<<s<<endl<<endl;
}	*/
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;//memset(rr,1,sizeof(rr));
	for(int i=1;i<=n;i++)cin>>a[i];
/*	tt(1,1,n);for(int i=1;i<=2*n;i++)cout<<f[i].l<<' '<<f[i].r<<' '<<f[i].m<<endl;
	o=f[1].m;
	for(int i=1;i<=o;i++){ff(1);cc(1);s++;ts();}
	//if(f[1].m==0){cout<<0;return 0;}*/
	for(int i=1;i<=n;i++)
	{  	k=a[i];s+=k;
		for(int j=1;j<=k;j++){h=i;while((h<=n)&&(a[h])){a[h]--;h++;}}  }    
	cout<<s;
	return 0;
}
