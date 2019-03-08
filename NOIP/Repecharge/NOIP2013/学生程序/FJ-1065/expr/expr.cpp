#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<cctype>
using namespace std;
int opr[1000]={},sopr=0;
int num[1000]={},snum=0;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	string expr;
	cin>>expr;
	int b=0,l=0,s,x,y;
	for(int i=0;i<expr.size();i++){
		if(isdigit(expr[i])) l++;
		else{
			if(l<=4) s=atoi(expr.substr(b,l).c_str());
			else s=atoi(expr.substr(b+l-4,4).c_str());
			num[++snum]=s;
			b=i+1;
			l=0;
			switch(expr[i]){
				case '+':
					opr[++sopr]=1;
					break;
				case '*':
					opr[++sopr]=2;
					break;
			}
		}
	}
	num[++snum]=atoi(expr.substr(b,l).c_str());
	while(sopr){
		s=opr[sopr];
		sopr--;
		if(s==2){
			x=num[snum--];
			y=num[snum--];
			num[++snum]=x*y;
		}
		else{
			x=num[snum--];
			y=num[snum--];
			num[++snum]=x+y;
		}
	}
	cout<<num[1]%10000;
	fclose(stdin);
	fclose(stdout);
}
