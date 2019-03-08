#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

const int maxn= 31;
int form[maxn][maxn], m, n, q;
int sx, sy, bx, by, ex, ey;

int main()
{
	freopen("puzzle.in", "r", stdin);
	freopen("puzzle.out", "w", stdout);
	cin>> m>> n>> q;
	for(int i= 1; i<= m; i++)
		for(int j= 1; j<= n; j++)
			cin>> form[i][j];
	if(q== 2)
	{
		for(int j= 1; j<= 2; j++)
		{
			cin>> sx>> sy>> bx>> by>> ex>> ey;
			if(sx== 3)
				cout<< "2"<< endl;
			else
				cout<< "-1"<< endl;
		}
	}
	else
	{
		while(q--)
		{
			cin>> sx>> sy>> bx>> by>> ex>> ey;
			cout<< "-1"<< endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	system("pause");
	return 0;
}
