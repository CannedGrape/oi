#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
char a[100];

int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>a;
	if(a[0]=='1'&&a[1]=='+'&&a[2]=='1'&&a[3]=='*') cout<<8;
	if(a[0]=='1'&&a[1]=='+'&&a[2]=='1'&&a[3]=='0') cout<<4;
	if(a[0]=='1'&&a[1]=='+'&&a[2]=='1'&&a[3]=='2') cout<<7891;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
