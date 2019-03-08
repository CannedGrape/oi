#include<cstdio>
#include<cstdlib>
int m,n,a[101],ans=0;
void flower(int d,int s){
	if(s==m){
		ans=(ans+1)%1000007;
		return;
	}
	if(s>m||d>n){
		return;
	}
	for(int i=a[d];i>=1;i--){
		flower(d+1,s+i);
	}
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	flower(1,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}