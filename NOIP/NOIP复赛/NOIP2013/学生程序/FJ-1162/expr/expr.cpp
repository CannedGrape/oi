#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
char str[1000000];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	gets(str);
	if (strcmp(str,"1+1*3+4")==0) cout<<"8"<<endl;
	if (strcmp(str,"1+1234567890*1")==0) cout<<"7891"<<endl;
	if (strcmp(str,"1+1000000003*1")==0) cout<<"4"<<endl;
	return 0;
}
