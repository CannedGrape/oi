#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int M=0;
struct huan{
	   bool upstar;
	   int where;
	   int kezhou;
};
int C[10001];
	huan A[10000+1][101];
	int B[10000+1][101];
long long ans;

int getdoor(int L,int where)
{     if(where<=C[L])
	   return where;
	else if(where%C[L]==0)return C[L];
		else return where%C[L];
}
int getdoor1(int L,int where)
{     if(where<=M)
	   return where;
	else if(where%M==0)return M;
		else return where%M;
}
int getfloor(int L,int where)
{ 
	while(!A[L][where].upstar)
	{where=getdoor1(L,where+1);}
	return where;
}
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	int N=0;
	cin>>N>>M;
    for(int i=1;i<=N;i++)
	{for(int j=1;j<=M;j++)
		{cin>>A[i][j].upstar>>A[i][j].where;
		   if(A[i][j].upstar)
			   {C[i]++;B[i][C[i]]=j;A[i][j].kezhou=C[i];}}
	}
	int begin=0; 
	cin>>begin;
	int L=1;
	begin+=1;
	while(L<=N)
	{	ans+=A[L][begin].where;
		if(A[L][begin].upstar)
		{begin=B[L][getdoor(L,A[L][begin].kezhou+A[L][begin].where-1)];}
		else {begin=B[L][getdoor(L,A[L][getfloor(L,begin)].kezhou+A[L][begin].where-1)];}
		L++;
	}
	cout<<ans%20123;
	//system("pause");
	fclose(stdin);
	fclose(stdout);
	return 0;
}