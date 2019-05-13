#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include "geometry.h"
#include "laser_projector.h"

using namespace std;

const int maxn=210000;
			int maxm=10000;

tpoint di[maxn],a[maxn];

int n,m,k;
double r;
		
void error() {
	printf("Check cannot be called without parameters!\n");
	exit(-1);
	return;
}

int main(int argc, char *arcv[]) {
	if (argc<2) error();
	char sinf1[200],sinf2[200];
	strcpy(sinf1,"tank");
	strcat(sinf1,arcv[1]);
	strcat(sinf1,".in");
	strcpy(sinf2,"tank");
	strcat(sinf2,arcv[1]);
	strcat(sinf2,".out");
	tlaser_projector projector;
	projector.clear();
	tpoint st;
	FILE *f=fopen(sinf1,"r");
	freopen(sinf2,"r",stdin);
	double x,y;
	fscanf(f,"%*lf %*lf %d %d %d",&n,&m,&k);
	scanf("%lf",&r);
	scanf("%lf %lf",&x,&y);
	st.assign(x,y);
	for (int i=1; i<=n; i++) {
		double x,y;
		scanf("%lf %lf",&x,&y);
		di[i].assign(x,y);
	}
	for (int i=1; i<=n; i++) {
		double x,y;
		fscanf(f,"%lf %lf",&x,&y);
		a[i].assign(x,y);
	}
	for (int i=1; i<=m; i++) {
		double x1,y1,x2,y2;
		fscanf(f,"%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
		projector.insertline(tline(tpoint(x1,y1),tpoint(x2,y2)));
	}
	projector.resetlimit(k);
	for (int i=1; i<=n; i++) {
		if (st.dis(a[i])<1e-3) continue;
		projector.clearhistory();
		projector.initialize(st,di[i]);
		projector.goforward(r);
		if (!projector.check(a[i])) {
			printf("Your output is not correct!\n");
			printf("The tank No.%d is not destroyed!\n",i);
			if (argc>2)
				if (arcv[2,0]=="-"&&arcv[2,1]=="t") printf("Final Position: %.6lf %.6lf\n",projector.position().cor_x(),projector.position().cor_y());
			return 0;
		}
		if (argc>2)
			if (arcv[2][0]=='-'&&arcv[2][1]=='t') printf("No %d, K=%d.\n",i,projector.currentk());
	}
	printf("Your output is correct,\n");
	printf("with striking distance %.6lf, given in the file.\n",r);
	return 0;
}
