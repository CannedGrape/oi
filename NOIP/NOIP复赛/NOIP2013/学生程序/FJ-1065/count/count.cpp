#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
using namespace std;
int n,x,ans=0;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&x);
	int i,j;
	for(i=1;i<=n;i++){
		j=i;
		while(j>0){
			if(j%10==x)
				ans++;
			j/=10;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
