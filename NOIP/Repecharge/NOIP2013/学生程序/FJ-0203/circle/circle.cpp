#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cmath>
#include <math.h>
#include <climits>
#include <ctime>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int n,m,k,x;

int ksm(int k)
{
	int t;
	if (k==1) return 10%n;
	t=ksm(k>>1);
    if (!(k&1))
      {
		  return (t%n)*t%n;
	  }
	else return (t%n)*(t%n)*10%n;
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	int ans;
	scanf("%d%d%d%d",&n,&m,&k,&x);
	ans=(ksm(k)*m+x)%n;
	printf("%d\n",ans);
	return 0;
}
