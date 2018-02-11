#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<iostream>
using namespace std;
int n,maxn=1;
int a[100001];
int team1[100001][2],team2[100001][2];
struct km
{
 int pos,sum;	
};
int dp1[100001];
int dp2[100001];
int dps()
{
 dp1[1]=a[1];
 dp2[1]=a[1];	
 int end1=1,ans1=1;
 int end2=1,ans2=1;
 for(int i=2; i<=n; i++)
 {	
  if(a[i]<dp2[end2]) 
   if(a[i]<dp1[end1]||ans2+1>ans1)
   {
	int t=end1+1;	
    while(a[i]<dp1[t-1]&&t>1) t--;
    dp1[t]=a[i];
    ans1=ans2+1;
    end1=max(end1,t);
   }
  
  if(a[i]>dp1[end1])
   if(a[i]>dp1[end2]||ans1+1>ans2) 
   {
    int t=end2+1;
    while(a[i]>dp2[t-1]&&t>1) t--;
    dp2[t]=a[i];
    ans2=ans1+1;
    end2=max(end2,t);
   } 	 
 } 
 maxn=max(ans1-1+ans1%2,ans2-1+ans2%2);
}

int main()
{
 freopen("flower.in","r",stdin);
 freopen("flower.out","w",stdout);	
 scanf("%d",&n);
 for(int i=1; i<=n; i++) scanf("%d",&a[i]);
 dps();
 printf("%d\n",maxn);
 return 0;	
}
