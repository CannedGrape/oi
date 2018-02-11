long long a,s,d,f;
#include<iostream>
using namespace std;
int q(long long w){
	if(d%2!=0 && d%23!=0 && d%29!=0 && d%17!=0 && d%19!=0 && d%13!=0 && d%3!=0 && d%5!=0 && d%7!=0 && d%9!=0 && d%11!=0){
	for(d=w-1;d>1 && d%11!=0;d--){
		if(w%d==0){
		d=1;
		return 1;
		}
	}
}
else return 0;
	d=0;
	return 0;
} 
int main(){
	freopen("culture.in","r",stdin);
	freopen("culture.out","w",stdout);
	cin>>a;
	for(s=a-1;s>1;s--){
		if(a%s==0){
		f=s;
		q(f);
		if(d==0){
			cout<<s;
			return 0;
			}
		} 
	}
	cout<<a;
	return 0;
}
