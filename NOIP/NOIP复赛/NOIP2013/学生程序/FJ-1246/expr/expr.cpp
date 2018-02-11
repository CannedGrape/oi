#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char a[1000000];
long long s;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
    gets(a);
    s=atoi(a)%10000;
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
