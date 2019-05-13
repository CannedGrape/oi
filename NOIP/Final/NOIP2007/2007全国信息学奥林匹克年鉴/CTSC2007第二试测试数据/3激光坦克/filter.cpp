#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "geometry.h"
#include "laser_projector.h"


#define EVAL_OUTPUT_FILE "/tmp/_eval.score"


const int maxn=210000;
const int maxm=10000;
const double zero=1e-3;
			

tpoint di[maxn],a[maxn];

int n,m,k;
int c1;
double r,c2,best;
FILE *fpin, *fpout, *fpans, *fpeval;

/* Output message and exit */
void output (char *s, int d)
{
	if (fpeval) {
		fprintf (fpeval, "%s\n%d\n", s, d);
		fclose (fpeval);
	}
	exit(d != 0);
}

/* Open files and check */
void open_files(char *sin, char *out, char *ans, char *eval_output)
{
	if ((fpin = fopen (sin, "r")) == NULL) {
		fprintf(stderr, "Can not open %s!\n", sin);
		output ("Can not open player's output file!", 0);
	}
	if ((fpeval = fopen (eval_output, "w")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", EVAL_OUTPUT_FILE);
		output ("Can not open eval record file!", 0);
	}

	if ((fpout = fopen (out, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", out);
		output ("Can not open player's output file!", 0);
	}

	if ((fpans = fopen (ans, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", ans);
		output ("Can not open standard answer!", 0);
	}
}

void error() {
	output("Invalid output or unexpected error!", 0);
}

int roundup(double x) {
	if (fabs(x-(int)x)<zero) return (int)x; else return (int)x+1;
}
 
int main (int argc, char *argv[])
{
	char c1, c2;
		
	if (argc != 4) {
		fprintf (stderr, "Usage: mason_e <in> <out> <ans>\n");
		output ("Invalid Call!", 0);
	}

	open_files (argv[1], argv[2], argv[3], EVAL_OUTPUT_FILE);

	tlaser_projector projector;
	projector.clear();
	tpoint st;
	double x,y;
	if (fscanf(fpin, "%d %lf %d %d %d",&c1,&c2,&n,&m,&k)==-1) error();
	if (fscanf(fpout, "%lf",&r)==-1) error();
	if (fscanf(fpout, "%lf %lf",&x,&y)==-1) error();
	st.assign(x,y);
	for (int i=1; i<=n; i++) {
		double x,y;
		if (fscanf(fpout, "%lf %lf",&x,&y)==-1) error();
		di[i].assign(x,y);
	}
	for (int i=1; i<=n; i++) {
		double x,y;
		if (fscanf(fpin,"%lf %lf",&x,&y)==-1) error();
		a[i].assign(x,y);
	}
	for (int i=1; i<=m; i++) {
		double x1,y1,x2,y2;
		if (fscanf(fpin,"%lf %lf %lf %lf",&x1,&y1,&x2,&y2)==-1) error();
		projector.insertline(tline(tpoint(x1,y1),tpoint(x2,y2)));
		if (tline(tpoint(x1,y1),tpoint(x2,y2)).inside(st)) error();
	}
	projector.resetlimit(k);
	fscanf(fpans, "%lf", &best);
	for (int i=1; i<=n; i++) {
		if (st.dis(a[i])<1e-3) continue;
		projector.clearhistory();
		projector.initialize(st,di[i]);
		projector.goforward(r);
		if (!projector.check(a[i])) {
			error();
			return 0;
		}
	}
	if (r<best+zero) 
		output("Right output!", 10);
	else if (r*c2>best)
		output("Right output!", c1);
	else 
		output("Right output!", c1+roundup((best-c2*r)*(10-c1)/((1-c2)*r)));
	
	return 0;
}

