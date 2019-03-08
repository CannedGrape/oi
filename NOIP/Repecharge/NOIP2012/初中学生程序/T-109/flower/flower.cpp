#include<iostream>
using namespace std;

int n,	/*n种花*/
	m;	/*m盆花*/
int i;	/*第i盆花*/ 
int da,	/*答案*/
	da2=0;	/*答案验证*/

int zi(int i){
	freopen("flower.in","r",stdin);
	int a[n];	/*每种花最多摆a[i]盆*/
	int b[n];	/*实际方案*/
	for(i=0;i<=n-1;i++){
		cin>>a[i];
		if(i>0){
			if(a[i]>a[i-1])a[i]=a[i-1];
		}
		if(i==0)b[i]=0;
	}
	
	while(i<=n){
		for(b[i]=m/n;b[i]<=a[i];b[i]++){
			if(i<=n-1)zi(i+1);
		}
		if(i==n){
			for(i=0;i<=n-1;i++)da2=da2+b[i];
			if(da2==m){
				da++;
				da2=0;
				i=n-1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n>>m;
	int a[n];	/*每种花最多摆a[i]盆*/
	for(i=0;i<=n-1;i++){
		cin>>a[i];
		if(i>0){
			if(a[i]>a[i-1])a[i]=a[i-1];
		}
	}
	da=0;
	zi(0);
	cout<<da;
	return 0;
}
		
	
	 
