#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
long long a,b;
int main()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	a=a%b;
	if(a==1) printf("1\n");
	else printf("%lld\n",(1+(a-1)*b)/a);
	fclose(stdin);
	fclose(stdout);
    return 0;	
}
