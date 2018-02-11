#include <stdio.h>
#include <stdlib.h>
struct level{
	int up[110];
	int key[110];
};
int ab(int i) {
	if(i<0) return i*(-1);
	else return i;
}
int main() {
	struct level lev[2200];
	int n,m,
		start,cur,t,
		i,j;
	long sum;
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d%d",&lev[i].up[j],&lev[i].key[j]);
		}
	}
	scanf("%d",&start);
	
	for(i=1;i<=n;i++) {
		cur=start;
		//printf("lev=%d,cur=%d\n",i,cur);
		sum+=lev[i].key[cur];
		if(lev[i].up[cur]==1) t=1;
		else t=0;
		for(j=start;t<=lev[i].key[start];j++) {
			if(j>m) {
				//printf("i=%d j=%d\n",i,j);
				j=j%m;
			}
			if(lev[i].up[j]==1) {
				//printf("1]i=%d cur=%d\n",i,cur);
				t++;
				cur=(cur+1)%m;
				//printf("i=%d cur=%d\n",i,cur);			
			}
		}
		start=cur;
		//printf("cur=%d\n",cur);
	}	
	printf("%ld\n",sum%20123);
	
	

	return 0;
}	
