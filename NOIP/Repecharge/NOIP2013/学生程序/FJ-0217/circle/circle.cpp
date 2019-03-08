#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>

using namespace  std;

int n,m,k,x,p,y;
long long ans;

long long search(int k)
{
	int tmp=k/2;
	long long tmpans;
	
	if (k==1) return p;
	
	tmpans=search(tmp);
	
	tmpans=(tmpans*tmpans) % n;
	if (k % 2 == 1) tmpans=(tmpans*p) % n;
	
	return tmpans;
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	
	int i,j;
	
	scanf("%d%d%d%d",&n,&m,&k,&x);
	
	p=10%n;
	ans=search(k);
	
	y=(x+m*ans) % n;
	
	printf("%d\n",y);
	
	//system("pause");
	return 0;
}
