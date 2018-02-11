#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,a[9]={0},x,ans=0,kk;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		if(i>=1 && i<=9 && x==i)
			ans++;
		if(i>=10 && i<=99){
			a[1]=i%10;
			a[2]=i/10;
			if(a[1]==x)
				ans++;
			if(a[2]==x)
				ans++;
		}
		if(i>=100 && i<=999){
			kk=i;
			for(int j=1;j<=3;j++){
				a[j]=kk%10;
				if(x==a[j])
					ans++;
				kk=kk/10;
			}
		}
		if(i>=1000 && i<=9999){
			kk=i;
			for(int j=1;j<=4;j++){
				a[j]=kk%10;
				if(x==a[j])
					ans++;
				kk=kk/10;
			}
		}
		if(i>=10000 && i<=99999){
			kk=i;
			for(int j=1;j<=5;j++){
				a[j]=kk%10;
				if(x==a[j])
					ans++;
				kk=kk/10;
			}
		}
		if(i>=100000 && i<=999999){
			kk=i;
			for(int j=1;j<=6;j++){
				a[j]=kk%10;
				if(x==a[j])
					ans++;
				kk=kk/10;
			}
		}
		if(i==1000000 && x==1)
			ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
