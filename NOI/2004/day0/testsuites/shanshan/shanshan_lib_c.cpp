#include<stdio.h>
#include<stdlib.h>
#include "shanshan_lib_c.h"
int __initialized = 0;
int __realTest = 0;
int __x;
int __count = 0;
FILE *log, *fout;

void Error(char* msg, int code)
{
	if(__realTest){
		fprintf(fout, "%d\n", code);
		fclose(fout);
	}else{
		printf(msg);
		printf("\n");
	}
	exit(0);
}

void init()
{
	char s[100];
	if(__initialized)
		Error("Already initialized.", 0);
	FILE *fp = fopen("shanshan.in", "r");
	if(fp == NULL)
		Error("Cannot open shanshan.in.", 0);
	fscanf(fp, "%s", s);
	if(s[0] == ':'){
		__realTest = 1;
		fscanf(fp, "%s", s);
		fout = fopen("shanshan.out", "w");
	}else{
		log = fopen("shanshan.log", "w");
		if(log == NULL)
			Error("Cannot create shanshan.log.", 0);
	}
	fclose(fp);
	__x = atoi(s);	
}

int show(int s1, int s2, int s3)
{
	int ret = 1;
	int best = s1;
	if(s1 < 1 || s1 > 1024 || s2 < 1 || s2 > 1024 || s3 < 1 || s3 > 1024) Error("Error in parameters.", -2);
	if(abs(s2 - __x) < abs(best - __x)){ ret = 2; best = s2; }
	if(abs(s3 - __x) < abs(best - __x)){ ret = 3; best = s3; }
	__count++;
	if(!__realTest){
		fprintf(log, "You called show(%d, %d, %d). Return value = %d\n", s1, s2, s3, ret);
	}else{
		if(__count > 5) Error("Too many calls.", -3);
	}
	return ret;
}

void answer(int x)
{
	if(!__realTest){
		fprintf(log, "Your answer is %d. You called %d times.\n", x, __count);
		fclose(log);
	}else{
		if(x == __x)
			fprintf(fout, "%d\n", __count);
		else
			Error("Wrong Answer.", -1);
		fclose(fout);
	}
}
