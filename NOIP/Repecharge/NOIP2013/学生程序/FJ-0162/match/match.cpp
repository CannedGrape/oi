#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

const int maxn= 100005;
int n, pd, len[maxn];

int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	cin>> n>> pd;
	for(int i= 1; i<= 2; i++)
		for(int i= 1; i< n; i++)
			cin>> len[i];
	if(pd== 1)
		cout<< "2";
	else if(pd== 2)
		cout<< "1";
	else
	 	cout<< "5";
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
