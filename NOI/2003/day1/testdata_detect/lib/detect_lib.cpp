#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <detect_lib.h>
#define MAXVERT 200
#define zero 1e-6
#define SWAP(x,y) tmp=x;x=y;y=tmp;

int vertn;
struct point{
	int x,y;
}vs[MAXVERT+100],rvs[MAXVERT+2];

int rv,count=-1;

double memx[20100][2];
int memix[20100];
double memy[20100][2];
int memiy[20100];
double standardarea;

FILE *ZIGLOG;

void WA()
{
	printf("Wrong answer after %d asks\n",count);
	exit(0);
};

void fillit(int a,int b,int c,int d,double e[][2],int f[])
{
	int tmp,i,aa;
	aa=b;
	if(a>b)
	{
		SWAP(a,b);
		SWAP(c,d);
	};
	for(i=a;i<=b;i++)
		if(i!=aa)
			e[i+10000][f[i+10000]++]=(d-c)*(i-a+0.0)/(b-a)+c;
};

void prog_initialize()
{
	int i;
	FILE *F;
	F = fopen("detect.in","r");
	ZIGLOG=fopen("detect.log","w");
	fscanf(F,"%d",&vertn);
	for(i=0;i<vertn;i++)
		fscanf(F,"%d %d",&vs[i].x,&vs[i].y);
	fclose(F);
	vs[vertn]=vs[0];
	rv=-2;
	count=0;
	memset(memix,0,sizeof(memix));
	memset(memiy,0,sizeof(memiy));
	for(i=0;i<vertn;i++)
	{
		fillit(vs[i].x,vs[i+1].x,vs[i].y,vs[i+1].y,memx,memix);
		fillit(vs[i].y,vs[i+1].y,vs[i].x,vs[i+1].x,memy,memiy);
	};
	standardarea=0;
	vs[vertn]=vs[0];
	for(i=0;i<vertn;i++)
		standardarea+=vs[i].x*vs[i+1].y-vs[i].y*vs[i+1].x;
	standardarea=fabs(standardarea)/2;
	fputs(ZIGLOG,"[INI] OK");
};

int isin(int a,int b,int c)
{
	return (a<=b&&b<=c)||(a>=b&&b>=c);
};

void docount()
{
	if(count<0)
	{
		puts(".\\/. Please call prog_initialize first!");
		exit(0);
	};
	count++;
};

int ask_intersect_x(int x,double *res)
{
	double tmp;
	docount();
	x+=10000;
	res[0]=memx[x][0];
	res[1]=memx[x][1];
	if(memix[x]>1)
		if(res[0]>res[1])
		{
			SWAP(res[0],res[1]);
		};
	return memix[x];
};

int ask_intersect_y(int y,double *res)
{
	double tmp;
	docount();
	y+=10000;
	res[0]=memy[y][0];
	res[1]=memy[y][1];
	if(memiy[y]>1)
		if(res[0]>res[1])
		{
			SWAP(res[0],res[1]);
		};
	return memiy[y];
};

int ask_x(int x,double *y1,double *y2)
{
	double res[2];
	int i;
	i=ask_intersect_x(x,res);
	*y1=res[0];
	*y2=res[1];
	return i;
};

int ask_y(int y,double *x1,double *x2)
{
	double res[2];
	int i;
	i=ask_intersect_y(y,res);
	*x1=res[0];
	*x2=res[1];
	return i;
};

void ret_n(int n)
{
	if(n!=vertn)WA();
	rv=-1;
};

void ret_area(double a)
{
	if(rv==-2)WA();
	rv=0;
	if(fabs(a-standardarea)<zero)return;
	WA();
};

void ret_vertex(int x,int y)
{
	int i,j;
	if(rv<0)WA();
	rvs[rv].x=x;
	rvs[rv++].y=y;
	if(rv>=vertn)
	{
		for(i=0;i<vertn;i++)
			if(rvs[i].x==vs[0].x&&rvs[i].y==vs[0].y)break;
		if(i>=vertn)WA();
		for(j=0;j<vertn;j++)
		{
			if(rvs[i].x!=vs[j].x||rvs[i].y!=vs[j].y)WA();
			i++;
			if(i==vertn)i=0;
		};
		printf("Accepted after %d asks.\n",count);
		exit(0);
	};
};
