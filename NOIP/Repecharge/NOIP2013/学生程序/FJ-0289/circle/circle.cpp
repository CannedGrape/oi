#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
int n,m,k,x;
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	  scanf("%d%d%d%d",&n,&m,&k,&x);
	int f=10;
	int l=x;
	for (int i=1;i<=f;i++)
	 {
		l+=m;
		if (l>=n) l%=n;
	 }
	printf("%d",l);
	fclose(stdin);fclose(stdout);
}
