#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int n, m, form[9505][50005], x, y, z, t;

int main()
{
	freopen("truck.in", "r", stdin);
	freopen("truck.out", "w", stdout);
	cin>> n>> m;
	for(int i= 1; i<= m; i++)
	{
		cin>> x>> y>>z;
		form[x][y]= max(form[x][y], z);
		form[y][x]= form[x][y];
	}
	for(int k= 1; k<= n; k++)
		for(int i= 1; i<= n; i++)
			for(int j= 1; j<= n; j++)
				if(i!= k&& form[i][k]&& form[k][j])
					form[i][j]= max(min(form[i][k],form[k][j]), form[i][j]);
	cin>> t;
	for(int i= 1; i<= t; i++)
	{
		cin>> x>> y;
		if(!form[x][y])
			cout<<"-1"<<endl;
		else
			cout<<form[x][y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	//system("pause");
	return 0;	
}
