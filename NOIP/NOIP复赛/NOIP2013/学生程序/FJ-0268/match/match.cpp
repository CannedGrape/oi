#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int C=99999997;
struct node{
	int x,num;
}s1[110000],s2[110000];
int n,l1[110000],l2[110000];
int t[110000],ans;
bool cmp(const node a,const node b){
	return a.x<b.x;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&l1[i]);
		s1[i].x=l1[i];
		s1[i].num=i;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&l2[i]);
		s2[i].x=l2[i];
		s2[i].num=i;
	}
	sort(s1+1,s1+1+n,cmp);
	sort(s2+1,s2+1+n,cmp);
	for (int  i=1;i<=n;i++){
		int k1=s1[i].num,k2=s2[i].num;
		t[k1]=k2-k1;
	}
	for (int i=1;i<=n;i++)
	if (t[i]>0)
		if(t[i]==-t[i+t[i]]){
			ans+=t[i]*2-1;
			ans%=C;
			t[i]=t[i+t[i]]=0;
		}
	if (n<=8000){	
	 for (int i=1;i<=n;i++)
	  if (t[i]>0){
			ans+=t[i];ans%=C;
			for (int j=i+1;j<=i+t[i];j++)
			   t[j]++;
	 }
	}else {
		for (int i=1;i<=n;i++)
	  if (t[i]>0){
			ans+=t[i];ans%=C;
			//for (int j=i+1;j<=i+t[i];j++)
			  // t[j]++;
	 }else if (t[i]<-1) ans=(ans+1)%C;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
