#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stdlib.h>
using namespace std;
int a[1001][1001]={0};
int main()
{
	int n,s=1,m,c;
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++)
		cin>>a[i][j];
	}
    cout<<m;
	fclose(stdin);
    fclose(stdout);
}
