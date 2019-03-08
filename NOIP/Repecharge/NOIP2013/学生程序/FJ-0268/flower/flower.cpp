#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int f[110000][3],h[110000],l[110000][3],tmp[110000],l1,l2,n,m,ans,s1[110000],s2[110000],len,tm[110000];
bool cmp(int a,int b){
	return a>b;
}
int res1(int x){
	int m=0;
	for (;x;x-=x & -x)
	  m=max(m,s2[x]);
	return m;
}
int res2(int x){
	int m=0;
	for (;x;x-=x & -x)
	  m=max(m,s1[x]);
	return m;
}
void add1(int x,int t){
	for (;x<=len-1;x+=x & -x)
	  if (t>s1[x]) s1[x]=t;
}
void add2(int x,int t){
	for (;x<=len-1;x+=x & -x)
	  if (t>s2[x]) s2[x]=t;
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
	  scanf("%d",&h[i]);
	  tmp[i]=h[i];
	  tm[i]=h[i];
	}
	if (n<=8000){
	//f[0][1]=1100000;
	f[1][1]=1;
	f[1][2]=1;
	for (int i=2;i<=n;i++)
	 for (int j=1;j<i;j++){
		if (h[i]>h[j] && f[j][2]+1>f[i][1])
		  f[i][1]=f[j][2]+1;
		if (h[i]<h[j] && f[j][1]+1>f[i][2])
		  f[i][2]=f[j][1]+1;	
		ans=max(ans,max(f[i][1],f[i][2]));
		//cout<<f[i][1]<<"    "<<i<<endl;
	 }
	if (ans%2==0) ans--;
	cout<<ans;
    }else {
		sort(tm+1,tm+1+n,cmp);
		sort(tmp+1,tmp+1+n);
		len=unique(tmp+1,tmp+1+n)-tmp;
		for (int i=1;i<=n;i++){
			int k=lower_bound(tmp+1,tmp+len,h[i])-tmp;
			int tt=lower_bound(tm+1,tm+len,h[i],cmp)-tm;
			//cout<<k<<"  "<<tt<<"   "<<h[i]<<endl;
			f[i][1]=res1(k-1)+1;
			f[i][2]=res2(tt-1)+1;
			add2(k,f[i][2]);
			add1(tt,f[i][1]);
			ans=max(ans,max(f[i][1],f[i][2]));
		}
	 if (ans%2==0) ans--;
	 cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
}
