#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

const int MAX=100000+5;
double n,m,r[MAX],d[MAX],s[MAX],t[MAX],left,note[MAX];

int main()
{
	freopen("classroom.in","r",stdin);
	freopen("classroom.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>r[i];
	for(int i=1;i<=m;i++)
		cin>>d[i]>>s[i]>>t[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=s[i];j<=t[i];j++)
		{
			r[j]-=d[i];
			if(r[j]<0)
			{
				cout<<"-1"<<endl<<i<<endl;
				goto outplace;
			}
		}
	}
	cout<<"0";
	outplace:
	fclose(stdin);fclose(stdout);
	return 0;
}
