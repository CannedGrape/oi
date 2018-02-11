#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<iostream>
using namespace std;
int n;
long long ans=0;
struct km
{
 int tar,pos;	
};
km a[100001];
bool cmp(km x,km y){return x.tar<y.tar;}

int work(int s,int e,int k,int sum)
{
 ans=ans+a[k].tar-sum;
 int i=k+1;
 while(!(a[i].pos<a[k].pos&&a[i].pos>=s)&&i<=n) i++;
 if(i<=n) 
 { 
  work(s,a[k].pos-1,i,a[k].tar);
 }
 i=k+1;
 while(!(a[i].pos>a[k].pos&&a[i].pos<=e)&&i<=n) i++;
 if(i<=n) 
 { 
  work(a[k].pos+1,e,i,a[k].tar);
 }	
}

int main()
{
 freopen("block.in","r",stdin);
 freopen("block.out","w",stdout);	
 scanf("%d",&n);
 for(int i=1; i<=n; i++) {scanf("%d",&a[i].tar);a[i].pos=i;}
 sort(a+1,a+n+1,cmp);
 work(1,n,1,0);	
 cout<<ans<<endl;
 return 0;	
}
