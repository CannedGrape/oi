#include<cstdio>
#include<cstring>
#include<cstdlib>
#define mset(I,J)	memset(I,J,sizeof(I))
#define loo(I,J,K)	for(I=J;I<=K;++I)
using namespace std;
const int M0=1000+100;
int dn,dp0[M0],dp1[M0];
long long dtb0[M0][M0],dtb1[M0][M0],aa;
struct D0{
	int i0,i1,i2[5];
}d0q[M0*M0];
int d0h,d0t;
int d0i[M0][M0];
void p0init(){
	d0h=d0t=0;
}
void p0e(D0 e){
	d0q[d0t]=e;
	d0t=(d0t+1)%M0;
}
D0 p0d(){
	D0 e;
	e=d0q[d0h];
	d0h=(d0h+1)%M0;
	return e;
}
long long pmx(long long ll0,long long ll1){
	return ll0>ll1?ll0:ll1;
}
bool p0vis(int *i0,int i1){
	int i2;
	if(i1<=31)
		i1-=1,i2=0;
	if(i1>31 && i1<=62)
		i1-=32,i2=1;
	if(i1>62 && i1<=93)
		i1-=63,i2=2;
	if(i1>93)
		i1-=94,i2=3;
	return (i0[i2]>>i1)&1;
}
void p0upd(int *i0,int i1){
	int i2;
	if(i1<=31)
		i1-=1,i2=0;
	if(i1>31 && i1<=62)
		i1-=32,i2=1;
	if(i1>62 && i1<=93)
		i1-=63,i2=2;
	if(i1>93)
		i1-=94,i2=3;
	i0[i2]=i0[i2]|(1<<i1);
}
void psssp(int src){
	D0 d00,d01;
	int i0,i1,i2,i3[4];
	long long ll0;
	mset(dtb0,63),mset(dtb1,63);
	aa=dtb0[0][0];
	
	dtb0[src][0]=0,dtb1[src][0]=dp0[src];
	d00.i0=src,d00.i1=0,mset(d00.i2,0);
	p0init(),p0e(d00);
	mset(d0i,0),d0i[src][0]=0;
	while(d0h!=d0t){
		d00=p0d();
		i0=d00.i0,i1=d00.i1,memcpy(i3,d00.i2,sizeof(i3));
		loo(i2,1,dn)
			if(!p0vis(i3,i2)){
				ll0=pmx((long long)dtb1[i0][i1]/dp1[i2],dtb0[i0][i1]);
				if(ll0<dtb0[i2][i1+1]){
					dtb0[i2][i1+1]=ll0;
					dtb1[i2][i1+1]=(long long)dtb1[i0][i1]*dp0[i2];
					if(i1+1<dn){
						d01=d00,d01.i0=i2,d01.i1=i1+1;
						p0upd(d01.i2,i2);
					}
					if(i1+1<dn)
						if(!d0i[i2][i1+1]){
							d0i[i2][i1+1]=d0t;
							p0e(d01);
						}
						else
						if(d0i[i2][i1+1])
							d0q[d0i[i2][i1+1]]=d01;
				}
			}
		d0i[i0][i1]=0;
		/*
		printf("%d %d %d\n",i0,i1,d00.i2[0]);
			loo(i0,1,dn){
		loo(i1,1,dn)
			printf("%I64d ",dtb0[i0][i1]);
		puts("");
		}
		puts("-------------------------------------------------------------");
			loo(i0,1,dn){
		loo(i1,1,dn)
			printf("%I64d ",dtb1[i0][i1]);
		puts("");
		}
		puts("=============================================================");
		*/
	}

	loo(i0,1,dn)
		if(aa>dtb0[i0][dn])
			aa=dtb0[i0][dn];
	
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	int i0;
	scanf("%d",&dn);
	scanf("%d%d",&dp0[0],&dp1[0]);
	loo(i0,1,dn)
		scanf("%d%d",&dp0[i0],&dp1[i0]);
	psssp(0);
	printf("%I64d\n",aa);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
