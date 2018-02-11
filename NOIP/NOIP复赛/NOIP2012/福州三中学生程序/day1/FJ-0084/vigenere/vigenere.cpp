#include<cstdio>
#include<cstring>
#include<cstdlib>
#define loo(I,J,K)	for(I=J;I<=K;++I)
#define mset(I,J)	memset(I,J,sizeof(I))
using namespace std;
const int M0=1000+100,M1=100;
char ds0[M0],ds1[M0],da0[M0];
int dmt[M1][M1];
int main(){
	freopen("vigenere.in","r",stdin);
	freopen("vigenere.out","w",stdout);
	
	int i0,i1,i2;
	scanf("%s%s",&ds0,&ds1);
	loo(i0,0,25)
		loo(i1,0,25)
			dmt[i0][i1]=(i1+(26-i0))%26;
	//The mat
	/*
	loo(i0,0,25){
		loo(i1,0,25)
			printf("%3d",dmt[i0][i1]);
		puts("");
	}
	*/
	loo(i0,0,strlen(ds0)-1)
		ds0[i0]-=ds0[i0]>'Z'?'a':'A';
	i1=0,mset(da0,0);
	loo(i0,0,strlen(ds1)-1){
		i2=ds1[i0]>'Z'?ds1[i0]-'a':ds1[i0]-'A';
		da0[i0]=dmt[ds0[i1]][i2];
		da0[i0]+=ds1[i0]>'Z'?'a':'A';
		++i1;
		if(i1==strlen(ds0))
			i1=0;
	}
	printf("%s\n",da0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
