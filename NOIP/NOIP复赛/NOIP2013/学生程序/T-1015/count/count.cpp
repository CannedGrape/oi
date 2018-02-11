#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
using namespace std;
int i,ans=0,x,b;
unsigned long long n;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n;
	cin>>x;
	for(i=1;i<=n;i++){
		b=i;
		while(b>=10){
			if(b%10==x){
				ans++;
			}
			if(b/10==x){
				ans++;
			}
			b=b/10;
		}
	}
	ans=ans+1;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
