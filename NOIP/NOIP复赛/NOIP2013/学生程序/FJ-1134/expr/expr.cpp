#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
using namespace std;

int s1[100005];
char s2[100005];
int cheng(int a,int b) {
	return ((a%10000)*(b%10000))%10000;
}
int jia(int a,int b) {
	return ((a%10000)+(b%10000))%10000;
}
int main() {
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	int p1=0,p2=0;
	char t;
	while ((t=getchar())!=EOF) {
		if (isdigit(t)) {
			char tt;
			int s=t-'0';
			while (isdigit(tt=getchar())) s*=10,s+=tt-'0'; 
			s1[++p1]=s;
			if (tt==EOF) break;
			else t=tt;
		}
		if (p2==0) s2[++p2]=t;
		if (t=='+' && p1>1) {
			if (s2[p2]=='*') p1--,s1[p1]=cheng(s1[p1],s1[p1+1]),s2[p2]='+';
			else p1--,s1[p1]=jia(s1[p1],s1[p1+1]);
		}
		if (t=='*' && p1>1) {
			if (s2[p2]=='*') p1--,s1[p1]=cheng(s1[p1],s1[p1+1]);
			else s2[++p2]='*';
		}		
	}
	while (p1!=1) {
		if (s2[p2]=='*') p1--,s1[p1]=cheng(s1[p1],s1[p1+1]),p2--;
		else p1--,s1[p1]=jia(s1[p1],s1[p1+1]),p2--;
	}
	cout << s1[1] << endl;
	return 0;
}
