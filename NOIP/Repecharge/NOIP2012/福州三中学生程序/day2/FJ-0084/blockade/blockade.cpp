#include<cstdio>
#include<cstring>
#include<cstdlib>
#define loo(I,J,K)	for(I=J;I<=K;++I)
#define mset(I,J)	memset(I,J,sizeof(I))
using namespace std;
const int M0=50+10;
int dn,dmt0[M0][M0],dmt[M0][M0],dmt1[M0][M0];
int dn0,ddg[M0],dp0[M0];
int dm,dp1[M0];
int d0q[M0],d0h,d0t;
bool d0v[M0],d0v0[M0];
void p0init(){
	d0h=d0t=0;
}
void p0e(int e){
	d0q[d0t]=e;
	d0t=(d0t+1)%M0;
}
int p0d(){
	int e;
	e=d0q[d0h];
	d0h=(d0h+1)%M0;
	return e;
}
void pbfs(int src){
	int i0,i1;
	mset(d0v,0),d0v[src]=1;
	p0init(),p0e(src);
	while(d0h!=d0t){
		i0=p0d();
		loo(i1,1,dn)
			if(i1!=i0 && !d0v[i1] && !d0v0[i1] && dmt0[i0][i1]){
				dmt[src][i1]=dmt[src][i0]+dmt0[i0][i1];
				d0v[i1]=1;
				p0e(i1);
			}
	}
}
bool pjdg(){
	int i0;
	bool fl;
	memcpy(dmt1,dmt,sizeof(dmt1));
	mset(dmt,0),pbfs(1);
	fl=1;
	loo(i0,2,dn0)
		if(dmt[1][dp0[i0]]){
			fl=0;
			break;
		}
	/*
	loo(i0,1,dn)
		printf("%d ",d0v0[i0]);
	puts("\n----------------------------------------------------");
	loo(i0,1,dn0)
		printf("%d ",dmt[1][dp0[i0]]);
	puts("\n=====================================================");
	*/
	memcpy(dmt,dmt1,sizeof(dmt));
	return fl;
}
bool prcs(int dpt,int lim){
	int i0,i1,i2;
	if(dpt>dm)
		return pjdg();
	i0=dp1[dpt],i2=0;
	loo(i1,1,dn)
		if(dmt[i0][i1]<=lim){
			d0v0[i1]=1;
			i2|=prcs(dpt+1,lim);
			d0v0[i1]=0;
		}
	return i2!=0;
}
int main(){
	int i0,i1,i2,i3,i4;
	freopen("blockade.in","r",stdin);
	freopen("blockade.out","w",stdout);
	
	scanf("%d",&dn);
	i4=0,mset(dmt0,0),mset(ddg,0);
	loo(i0,1,dn-1){
		scanf("%d%d%d",&i1,&i2,&i3);
		dmt0[i1][i2]=dmt0[i2][i1]=i3;
		i4+=i3;
		++ddg[i1],++ddg[i2];
	}
	
	dn0=0;
	loo(i0,1,dn)
		if(ddg[i0]==1)
			++dn0,dp0[dn0]=i0;
	/*
	loo(i0,1,dn0)
		printf("%d ",dp0[i0]);
	puts("");
	*/
	mset(dmt,0),mset(d0v0,0);
	loo(i0,1,dn)
		pbfs(i0);
	/*
	loo(i0,1,dn){
		loo(i1,1,dn)
			printf("%5d",dmt[i0][i1]);
		puts("");
	}
	*/
	scanf("%d",&dm);
	loo(i0,1,dm)
		scanf("%d",&dp1[i0]);
	/*
	printf("%d\n",dm);
	loo(i0,1,dm)
		printf("%d ",dp1[i0]);
	puts("");
	*/
	i0=0,i2=i4;
	while(i2-i0>1){
		i1=(i0+i2)>>1;
		mset(d0v0,0);
	//	printf("%d %d %d\n",i0,i1,i2);
		if(prcs(1,i1))
			i2=i1;
		else
			i0=i1+1;
	}
	mset(d0v0,0);
	if(i2==i4 && !prcs(1,i4))	
		printf("-1\n");
	else{
		mset(d0v0,0);
		if(prcs(1,i0))
			printf("%d\n",i0);
		else
			printf("%d\n",i2);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
