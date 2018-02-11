#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "detect_lib.h"

#define MAXVERT 200
#define zero 1e-6
#define SWAP(x,y) tmp=x;x=y;y=tmp;

int vertn;
struct point{
	int x,y;
}vs[MAXVERT+100],rvs[MAXVERT+2];

int rv=-3,count=-1;

double memx[20100][2];
int memix[20100];
double memy[20100][2];
int memiy[20100];
double standardarea;

char msg[200];

static int isInitialized = 0, isInTest = 0;
int score;

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

void WriteLog(char* cat, char* msg)
{
	FILE* log;
	if (!isInTest) {
		log = fopen("detect.log", "a");
		fprintf(log, "[%s] %s\n", cat, msg);
		fclose(log);
	}
}

void Error(char* msg)
{
	WriteLog("ERR", msg);
	sprintf(msg,"Score = %d",score);
	WriteLog("SCR", msg);
	exit(1);
}

void prog_initialize()
{
	int i;
	char s[100], password[] = "detect";
	FILE *F;

	if (isInitialized) Error("prog_initialize: Reinitialization!");

	fclose(fopen("detect.log","w"));

	F = fopen("detect.in","r");
	
	fscanf(F,"%d",&vertn);
	if (vertn < 0) {
		vertn = (-vertn) ^ 0x3f;
		fscanf(F, "%s", s);
		for (i=0; s[i]; i++) s[i] = s[i] ^ 0x3f;
		if (strcmp(s, password) != 0) Error("Invalid format!");
		for (i=0; i<vertn; i++) {
			fscanf(F, " %d %d", &vs[i].x, &vs[i].y);
			vs[i].x ^= 0x3f3f3f3f;
			vs[i].y ^= 0x3f3f3f3f;
		}
		isInTest = 1;
	} else {
		for(i=0;i<vertn;i++)
			fscanf(F," %d %d",&vs[i].x,&vs[i].y);
		isInTest = 0;
	}
	fclose(F);

	vs[vertn]=vs[0];
	rv=-2;
	count=0;
	memset(memix,0,sizeof(memix));
	memset(memiy,0,sizeof(memiy));
	for(i=0;i<vertn;i++)
	{
		fillit(vs[i].x, vs[i+1].x, vs[i].y, vs[i+1].y, memx, memix);
		fillit(vs[i].y, vs[i+1].y, vs[i].x, vs[i+1].x, memy, memiy);
	};
	standardarea=0;
	vs[vertn]=vs[0];
	for(i=0;i<vertn;i++)
		standardarea+=vs[i].x*vs[i+1].y-vs[i].y*vs[i+1].x;
	standardarea=fabs(standardarea)/2;
	
	isInitialized = 1;
	sprintf(msg,"prog_initialize: OK, %d points read.",vertn);
	WriteLog("INI", msg);
};

int isin(int a,int b,int c)
{
	return (a<=b&&b<=c)||(a>=b&&b>=c);
};

void docount()
{
	if(count<0)
		Error(".\\/. Please call prog_initialize first!");
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
	sprintf(msg,"ask_x called with x0=%d, returned %d with y0=%.5lf, y1=%.5lf",x,i,res[0],res[1]);
	WriteLog("ASK",msg);
	return i;
};

int ask_y(int y,double *x1,double *x2)
{
	double res[2];
	int i;
	i=ask_intersect_y(y,res);
	*x1=res[0];
	*x2=res[1];
	sprintf(msg,"ask_y called with y0=%d, returned %d with x0=%.5lf, x1=%.5lf",y,i,res[0],res[1]);
	WriteLog("ASK",msg);
	return i;
};

int score;

void ret_n(int n)
{
	if(rv!=-1)Error("Bad call of ret_n!");
	if(n!=vertn)Error("Wrong vertex number!");
	score+=1;
	rv=0;
	sprintf(msg,"ret_n called with n=%d",n);
	WriteLog("RET",msg);
};

void ret_area(double a)
{
	if(rv!=-2)Error("Bad call of ret_area!");
	rv=-1;
	if(fabs(a-standardarea)<zero)
		score+=2;
	else
		WriteLog("ERR","Wrong area!");
	sprintf(msg,"ret_area called with area=%.2lf",a);
	WriteLog("RET",msg);
};

double sqr(double x)
{
	return x*x;
};

void ret_vertex(int x,int y)
{
	int i,j;
	if(rv<0)Error("Call ret_area and ret_n first!");
	sprintf(msg,"ret_vertex called with x=%d y=%d",x,y);
	WriteLog("RET",msg);
	rvs[rv].x=x;
	rvs[rv++].y=y;
	if(rv>=vertn)
	{
		for(i=0;i<vertn;i++)
			if(rvs[i].x==vs[0].x&&rvs[i].y==vs[0].y)break;
		if(i>=vertn)Error("Wrong vertex!");
		for(j=0;j<vertn;j++)
		{
			if(rvs[i].x!=vs[j].x||rvs[i].y!=vs[j].y)Error("Wrong vertex!");
			i++;
			if(i==vertn)i=0;
		};
		score+=2;
		if(count<=700)score+=5;else score+=(int)(5*exp(-0.4*sqr((700.0-count)/count)));
		sprintf(msg,"Count = %d",count);
		WriteLog("CNT", msg);
		sprintf(msg,"Score = %d",score);
		WriteLog("SCR", msg);
		exit(0);
	};
};
