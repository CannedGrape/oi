#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

const int maxn= 1000;
int n, m, k, x, que[maxn], p= 1;

int dg(int y)
{
	if(y== 0)
		return 1;
	else if(y== 1)
		return 10;
	else if(y%2)
		return dg(y/2)*dg(y/2)*10%n;
	else
		return dg(y/2)*dg(y/2)%n;
}

int main()
{
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	cin>> n>> m>> k>> x;
	for(int i= 0; i< n; i++)
		que[i]= i;
	p= dg(k);
	n--;
	while(p--)
	{
		if(x+ m> n)
			x= (x+ m)% (n+ 1);
		else
			x= x+ m;
	}
	cout<< x;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
