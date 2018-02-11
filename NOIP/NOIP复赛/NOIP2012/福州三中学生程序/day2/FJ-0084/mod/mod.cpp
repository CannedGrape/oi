#include<cstdio>
#include<cstring>
#include<cstdlib>
#define loo(I,J,K)	for(I=J;I<=K;++I)
#define mset(I,J)	memset(I,J,sizeof(I))
using namespace std;
int da,db,dx;
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	
	scanf("%d%d",&da,&db);
	dx=1;
	while(da*dx%db!=1)
		++dx;
	printf("%d\n",dx);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
