#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn= 100005;
long long n, len[maxn], res, h;

int pd()
{
	for(int i= h; i< n; i++)
		if(len[i]< 0)
		{
			res++;
			h= i;
			return i;
		}
	return -1;
}

int main()
{
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	cin>> n;
	for(int i= 0; i< n; i++)
	{
		cin>> len[i];
		len[i]*=-1;
	}
	while(h!= -1)
	{
		h= pd();
		for(int i= h; i< n; i++)
		{
			if(len[i]< 0)
				len[i]++;
			else
				break;
		}
	}
	cout<< res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
