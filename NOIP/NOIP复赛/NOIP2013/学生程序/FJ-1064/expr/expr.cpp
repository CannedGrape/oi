#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
//==================
char a[1000],
	 fuhao[1000];
int b[1000];

int* c=new int [1000];

int strlena,m=1,i,j=0;

int Ans;

bool Wuchengchu(int i) {
	for (int j=i; j<=m; j++)
		if (j=='*' || j=='/')
			return 0;
	return 1;
}

void Jia() {
	c[i]=c[i]+c[i+1];
	delete c[i+1];
	i--;
}

void Jian() {
	c[i]=c[i]-c[i+1];
	delete c[i+1];
	i--;
}

void Cheng() {
	c[i]=c[i]*c[i+1];
	delete c[i+1];
	i--;
}

void Chu () {
	c[i]=c[i]/c[i+1];
	delete c[i+1];
	i--;
}

void Fuhaopanduan (){					//对符号进行判断 
	if(fuhao[i]='*') Cheng();
	else
		if(fuhao[i]='/') Chu();
		else
			if(Wuchengchu()==0)
				if(fuhao[i]='+') Jia();
				else Jian();
			else {
				i++;
				Fuhaopanduan();
			}
	if (i==1)
		return;
	else {
		i=1;
		Fuhaopanduan();
	}
}
int main ( ) {
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    //================================
	gets(a);
	strlena=strlen(a);
//	初始化数据结束。 
	for (i=0; i<strlena; i++) {
    	if (a[i]-'0'<10 && a[i]-'0'>=0)
    		b[i]=a[i]-'0';
    	else {
    		fuhao[j++]=a[i];
			b[i]=-1;
		}
	}
//	数字倒一边，符号倒另一边=- =
	
	j=1;
	for (i=0; i<strlena; i++) {
		if (b[i]!=-1) {
			c[m]=b[i]*j+c[m];
			j=j*10;
		}
		else {
			m++;
			j=1;
		}
	}
//	单个数字整合成lld形式。（ l64d . 
	i=1;
	Fuhaopanduan();
	
	Ans=c[1]%10000;
	printf("%d",Ans);
	//================================
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
