#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,i,j,a[10000][10000];
int main(){
	cin>>n>>m;
	for (i=1;i<=m;i++){
	  cin>>a[i,1];
	  for (j=1;j<=a[i,1];j++){
		cin>>a[i,j+1];
	  }
    }  
    cout<<m;
	
	return 0;
}
