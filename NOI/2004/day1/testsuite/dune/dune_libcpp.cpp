#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxN 1001
#define MaxM 4001

FILE *fin;
FILE *fout;

static int n, m, nowpos, nowroad, Count, score;
static int stone;
static int havestone[MaxN];
static int cave, channel;
static int g[MaxN][MaxM], h[MaxN][MaxM];
static int d[MaxN];
static int Initialized = 0, isInTest = 0;

static void Error(char *message)
{
	if (!isInTest) fprintf(fout, "%s\n", message);
	else fprintf(fout, "-1\n");
	fclose(fin);
	fclose(fout);
    exit(0);
}

void init(void);
void put_sign(void);
void take_sign(void);
void walk(int);
void look(int *,int *);
void report(int,int);

void init()
{
    int i,j,k;
	if (Initialized) {
		Error("You have called init() twice!");
	}
	fin = fopen("dune.in", "r");
    Initialized=1;
    fscanf(fin, "%d", &n);
    if (n == 0) {
    	isInTest = 1;
    	fscanf(fin, "%d %d", &n, &m);
    	fout = fopen("dune.out", "w");
    }
    else fout = fopen("dune.log", "w");
	if (!isInTest) fprintf(fout, "init()\n");
    m = 0;
    for (i = 1; i <= n; i++) {
        fscanf(fin, "%d", &d[i]);
        m += d[i];
        for (j = 0; j < d[i]; j++) {
            fscanf(fin, "%d", g[i][j]);
        }
    }
    m /= 2;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < d[i]; j++) {
            for (k = 0; k < d[g[i][j]]; k++) {
                if (g[g[i][j]][k] == i) break;
            }
            h[i][j] = k;
        }
    }
    nowpos = 1;
    nowroad = 0;
    stone = 1;
    memset(havestone, 0, sizeof(havestone));
    Count = 0;
    score = 0;
    cave = channel = 0;
}

void put_sign()
{
	if (!isInTest) fprintf(fout, "put_sign()\n");
    if (!Initialized) Error("You must call init() first!");
    if (!stone) Error("Error in put_sign()!");
    stone = 0;
    havestone[nowpos] = 1;
}

void take_sign()
{
	if (!isInTest) fprintf(fout, "take_sign()\n");
    if (!Initialized) Error("You must call init() first!");
    if (!havestone[nowpos]) Error("Error in take_sign()!");
    stone = 1;
    havestone[nowpos] = 0;
}

void walk(int k)
{
    int nextpos = 0;
	if (!isInTest) fprintf(fout, "walk(%d)\n", k);
    if (!Initialized) Error("You must call init() first!");
    nextpos = g[nowpos][(nowroad + k) % d[nowpos]];
    nowroad = h[nowpos][(nowroad + k) % d[nowpos]];
    nowpos = nextpos;
    Count++;
}

void look(int *roadnum, int *stone)
{
	if (!isInTest) {
		fprintf(fout, "look(d, sign), returned with d=%d, sign=", d[nowpos]);
		if (havestone[nowpos]) fprintf(fout, "True\n");
		else fprintf(fout, "False\n");
	}
    if (!Initialized) Error("You must call init() first!");
    *roadnum = d[nowpos];
    *stone = havestone[nowpos];
}

void report(int ncave, int nchannel)
{
	if (!isInTest) fprintf(fout, "report(%d, %d)\n", ncave, nchannel);
    if (!Initialized) Error("You must call init() first!");
    if (!isInTest) {
	    if (ncave == n) fprintf(fout, "The number of caves is correct!\n");
	    else fprintf(fout, "The number of caves is NOT correct!\n");
	    if (nchannel == m) fprintf(fout, "The number of channels is correct!\n");
	    else fprintf(fout, "The number of channels is NOT correct!\n");
	    fprintf(fout, "You have walked %d time(s)!\n", Count);
	}
	else {
		fprintf(fout, "%d\n", Count);
		fprintf(fout, "%d %d\n", ncave, nchannel);
	}
	fclose(fin);
	fclose(fout);
    exit(0);
}
