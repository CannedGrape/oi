#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
string s,x,y,z;
int main()
{
	ifstream fin("expr.in");
	ofstream fout("expr.out");
	fin>>s;
	for(int i=0;i<10000000000;i++)
    /*if(s[i]='+')
    {
		for(int j=0;j<=i;j++)
		x[j]=s[j];*/
		while(s[i]!='*'||s[i]!='+')
		{
			x=s;
			
			
			
			
			
			
			
			
			
			
			
			
			
			}
		
		/*
		}
		if(s[i]='*')
		{
			for(int k=0;k<=i;k++)
			y[k]=s[k];
			
			*/
			}
	
	fout<<s<<endl;
	return 0;

}
