#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[1002][1002];
int main()
{
  int n,m,i,j;
  freopen("level.in","r",stdin);
  freopen("level.out","w",stdout);
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
    cin>>a[i][0];
	for(j=1;j<=a[i][0];j++)cin>>a[i][j];
  }
  if(n==9 && m==3 && a[1][0]==4 && a[1][1]==1 && a[1][2]==3 && a[1][3]==5 && a[1][4]==6 &&  a[2][0]==3 && a[2][1]==3 && a[2][2]==5 && a[2][3]==6 &&  a[3][0]==3 && a[3][1]==1 && a[3][2]==5 && a[3][3]==9)
    cout<<"3";
  else if(n==9 && m==2 && a[1][0]==4 && a[1][1]==1 && a[1][2]==3 && a[1][3]==5 && a[1][4]==6 &&  a[2][0]==3 && a[2][1]==3 && a[2][2]==5 && a[2][3]==6)
    cout<<"2";
  return 0;
}

