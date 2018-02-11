#include<iostream>
using namespace std;
int main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	int n,p;  
	cin>>n;
	for(p=n/2;p>=1;p--){
		if(n%p==0){
			cout<<p;
			p=0;
		}
	}
	return 0;
}
	
