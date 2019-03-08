#include<cstdio>
#include<cstring>
#include<cstdlib>
#define loo(I,J,K)	for(I=J;I<=K;++I)
#define mset(I,J)	memset(I,J,sizeof(I))
using namespace std;
const int M0=100000+100;
const int TH=21,TL=1<<TH,TD=TL>>1;
int pmn(int i0,int i1){
	return i0<i1?i0:i1;
}
struct D0{
	int c[TL],t[TL];
	void init(int *a,int l){
		int i0,i1;
		mset(c,63);
		loo(i0,1,l)
			c[i0+TD]=a[i0];
		mset(t,0);
		loo(i0,1,l){
			i1=(i0+TD)>>1;
			while(i1){
				c[i1]=pmn(c[i1+i1],c[i1+i1+1]);
				i1=i1>>1;
			}
		}
	}
	void snk(int idx){
		int i0,i1;
		idx=idx+TD;
		i0=idx,i1=0;
		while(i0)
			i0=i0>>1,++i1;
		--i1;
		while(i1>=1){
			i0=idx>>i1;
			t[i0+i0]+=t[i0];
			t[i0+i0+1]+=t[i0];
			t[i0]=0;
			c[i0]=pmn(c[i0+i0]-t[i0+i0],c[i0+i0+1]-t[i0+i0+1]);
			--i1;
		}
	}
	void upd(int idx){
		idx=(idx+TD)>>1;
		while(idx){
			c[idx]=pmn(c[idx+idx]-t[idx+idx],c[idx+idx+1]-t[idx+idx+1]);
			idx=idx>>1;
		}
	}
	void chg(int l,int r,int i0){
		int l0,r0;
		l0=l,r0=r;
		l=l+TD-1,r=r+TD+1;
		while(r-l>1){
			if(!(l&1))	t[l+1]+=i0;
			if(r&1)		t[r-1]+=i0;
			l=l>>1;
			r=r>>1;
		}
		upd(l0-1);
		upd(r0+1);	
	}
	int qry(int l,int r){
		int i0;
		i0=~0U>>1;
		snk(l-1);
		snk(r+1);
		l=l+TD-1,r=r+TD+1;
		while(r-l>1){
			if(!(l&1))	i0=pmn(i0,c[l+1]-t[l+1]);
			if(r&1)		i0=pmn(i0,c[r-1]-t[r-1]);
			l=l>>1;
			r=r>>1;
		}
		return i0;
	}
}d0t;
int dn,dm,ds[M0];
int main(){
	freopen("classrom.in","r",stdin);
	freopen("classrom.out","w",stdout);
	
	int i0,i1,i2,i3;
	scanf("%d%d",&dn,&dm);
	loo(i0,1,dn)
		scanf("%d",&ds[i0]);
	d0t.init(ds,dn);
	/*
	printf("%d\n",d0t.qry(2,3));
	loo(i1,1,dn)
		printf("%d ",d0t.qry(i1,i1));
	puts("");	
	*/
	loo(i0,1,dm){
		scanf("%d%d%d",&i1,&i2,&i3);
		if(d0t.qry(i2,i3)<i1){
			printf("-1\n%d\n",i0);
			break;
		}
		else
			d0t.chg(i2,i3,i1);
		/*
		printf("%d\n",d0t.qry(2,dn));
		
		loo(i1,1,dn)
			printf("%d ",d0t.qry(i1,i1));
		puts("");
		printf("%d\n",d0t.qry(2,dn));
		loo(i1,1,dn)
			printf("%d ",d0t.qry(i1,i1));
					
		puts("");
		*/
	}
	if(i0==dm+1)
		puts("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
