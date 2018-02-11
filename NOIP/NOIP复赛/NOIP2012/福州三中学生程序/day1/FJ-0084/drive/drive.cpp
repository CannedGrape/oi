#include<cstdio>
#include<cstring>
#include<cstdlib>
#define mset(I,J)	memset(I,J,sizeof(I))
#define loo(I,J,K)	for(I=J;I<=K;++I)
using namespace std;
const int M0=100000,M1=10000;
int dn,dm,dh[M0],dhist;
int dx0,dx1[M0],dss1[M0];
int dcls[M0][2];
int ds0,ds1,as0,as1;
int pab(int i0){
	return i0<0?-i0:i0;
}
int pds(int i0,int i1){
	return pab(dh[i0]-dh[i1]);
}
void pslv(int s,int x){
	int i0,i1,i2,i3;
	ds0=0,ds1=0;
	i0=0,i1=s,i3=0;
	while(1){
	//	printf("%d\n",i3);
		if(!i0){
			i2=pds(i1,dcls[i1][1]);
			if(i3+i2>x || !dcls[i1][1])
				break;
			ds0+=i2,i3+=i2,i1=dcls[i1][1];
		}
		if(i0){
			i2=pds(i1,dcls[i1][0]);
			if(i3+i2>x || !dcls[i1][0])
				break;
			ds1+=i2,i3+=i2,i1=dcls[i1][0];
		}
		i0=1-i0;
	}
	/*
	puts("");
	printf("%d %d %d %d\n",s,x,ds0,ds1);
	
	puts("========================================================================");
	*/
}
int main(){
	freopen("drive.in","r",stdin);
	freopen("drive.out","w",stdout);
	
	int i0,i1,i2,i3,i4,i5,i6;
	//Read
	scanf("%d",&dn);
	dhist=1;
	loo(i0,1,dn){
		scanf("%d",&dh[i0]);
		if(dh[i0]>dh[dhist])
			dhist=i0;
	}
	dh[0]=~0U>>1;
	scanf("%d",&dx0);
	scanf("%d",&dm);
	loo(i0,1,dm)
		scanf("%d%d",&dss1[i0],&dx1[i0]);
	//Pre Computation
	loo(i0,1,dn-1){
		i2=i3=0;
		loo(i1,i0+1,dn){
			i4=pds(i0,i1),i5=pds(i0,i2),i6=pds(i0,i3);
			if(!i2 || i4<i5 || i4==i5 && dh[i2]>dh[i1]){
				if(!i3 || i5<i6 || i5==i6 && dh[i3]>dh[i2])
					i3=i2;
				i2=i1;
			}
			else
			if(!i3 || i4<i6 || i4==i6 && dh[i3]>dh[i1])
				i3=i1;
		}
		dcls[i0][0]=i2,dcls[i0][1]=i3;
	}
	/*
	loo(i0,1,dn-1)
		printf("%d %d\n",pds(i0,dcls[i0][0]),pds(i0,dcls[i0][1]));
	puts("---------------------------------------------------");
	*/
	//Procedure 1
	i1=dhist,as0=1,as1=0;
	loo(i0,1,dn){
		pslv(i0,dx0);
		if(!ds1)	continue;
		if(!as1 || as0*ds1>as1*ds0)
			i1=i0,as0=ds0,as1=ds1;
		else
		if(as0*ds1==as1*ds0 && dh[i1]<dh[i0])
			i1=i0;
	//	printf("%d %d\n",as0,as1);
	}
	printf("%d\n",i1);
	//Procedure 2
	loo(i0,1,dm){
	//	printf("%d %d\n",dss1[i0],dx1[i0]);
		pslv(dss1[i0],dx1[i0]);
		printf("%d %d\n",ds0,ds1);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
