#include<cstdio>
#include<cstdlib>
int zhi[10000]={0,2};
int top=1;
bool prime(int num){
	if(num==1) return false;
	for(int i=1;i<=top;i++){
		if(num%zhi[top]==0){
			return false;
		}
	}
	zhi[++top]=num;
	return true;
}
int main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	zhi[1]=2;
	int n;
	scanf("%d",&n);
	for(int i=n;i>=1;i--){
		int j=n/i;
		if(i*j==n&&prime(i)&&prime(j)&&i>j){
			printf("%d",i);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
