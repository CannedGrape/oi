#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<string>
using namespace std;
int n,p;
int num;
long long f[1000001]={};
long long tz;
long long fs[1000001]={};
long long maxfs[1000001]={};
long long fss=-0xff;
int main(){
	int i,j;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		num%=p;
		f[i]=f[i-1]+num;
		tz=-0xff;
		for(j=0;j<i;j++)
			if(tz<f[i]-f[j])
				tz=f[i]-f[j];
		tz%=p;
		if(i==1){fs[i]=tz;maxfs[i]=tz*2;}
		else{
			fs[i]=maxfs[i-1]%p;
			if(maxfs[i-1]>fs[i]+tz) maxfs[i]=maxfs[i-1];
			else maxfs[i]=fs[i]+tz;
		}
		if(fs[i]>fss) fss=fs[i];
	}
	printf("%I64d",fss);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
