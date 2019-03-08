#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,m,k,x;
long long tmp;
long long exp(int a,int k,int b){
    if (k==1) return a%b;
    if (k==0) return 1;
	long long t=exp(a,k>>2,b);
	if (k & 1==0) t=t*t%b;
	if (k & 1==1) t=((t*t%b)*(a%b))%b;
	return t;	
}
int main(){
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&x);
    m=m%n;x=x%n;
    tmp=exp(10,k,n);
    long long ans=(x+(m*tmp)%n)%n;
    cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
