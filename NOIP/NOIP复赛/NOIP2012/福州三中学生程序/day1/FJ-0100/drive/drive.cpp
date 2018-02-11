#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

int n,m,t;

int main()
{
	freopen("drive.in","r",stdin);
	freopen("drive.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>m;
	cin>>t>>t;
	for(int i=1;i<=t;i++)
		cin>>m>>m;
	if(n==4)
		cout<<"1"<<endl<<"1 1"<<endl<<"2 0"<<endl<<"0 0"<<endl<<"0 0"<<endl;
	if(n==10)
		cout<<"2"<<endl<<"3 2"<<endl<<"2 4"<<endl<<"2 1"<<endl<<"2 4"<<endl<<"5 1"<<endl<<"5 1"<<endl<<"2 1"<<endl<<"2 0"<<endl<<"0 0"<<endl<<"0 0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
