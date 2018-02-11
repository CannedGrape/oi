#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
int main(){
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	int n,m,k,p;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>p;
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
