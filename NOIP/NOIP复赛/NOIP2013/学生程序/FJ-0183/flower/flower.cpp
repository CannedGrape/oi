#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define maxn 100010
using namespace std;
int n;
int h[maxn];
int fmin(int a,int b){
	return a<b?a:b;
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&h[i]);
	int ret=0;
	for (int i=2;i<=n;i++) {
		if (h[i-1]>h[i]) continue;
		ret++;
	}
	int tmp1=2*ret+1;ret=0;
	for (int i=2;i<=n;i++){
		if (h[i-1]<h[i]) continue;
		ret++;
	}
	int tmp2=2*ret+1;
	cout<<fmin(tmp1,tmp2)<<endl;
	fclose(stdin);
   fclose(stdout);
}
