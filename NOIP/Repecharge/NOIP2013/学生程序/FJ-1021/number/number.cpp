#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
int a[1000001]={0},n,p,tezhengzhi[1000001]={0},fenshu[1000001]={0};
bool b;
int tb(int k){
	int mix=-100000,ans=0;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k-i+1;j++){
			for(int t=1;t<=j;t++)
				ans=ans+a[i+t-1];
			if(ans>mix)
				mix=ans;
			ans=0;
		}
	return mix;
}	
int vs(int k){
	int ans=-100000;
	for(int i=1;i<=k-1;i++)
		if(tezhengzhi[i]>ans)
			ans=tezhengzhi[i];
	return ans;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ans=-100000;
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	tezhengzhi[1]=a[1];
	for(int i=2;i<=n;i++)
		tezhengzhi[i]=tb(i);
	fenshu[1]=tezhengzhi[1];
	tezhengzhi[1]=tezhengzhi[1]+fenshu[1];
	for(int i=2;i<=n;i++){
		fenshu[i]=vs(i);
		tezhengzhi[i]=tezhengzhi[i]+fenshu[i];
	}
	for(int i=1;i<=n;i++)
		if(fenshu[i]>ans)
			ans=fenshu[i];
	if(ans<0){
		ans=0-ans;
		if(ans%p!=0)
			cout<<'-';
	}
	cout<<ans%p;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
