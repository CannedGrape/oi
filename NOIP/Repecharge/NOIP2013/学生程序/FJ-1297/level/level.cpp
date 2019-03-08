#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int n,m;
	ifstream fin("level.in");
	ofstream fout("level.out");
	fin>>n>>m;
	fout<<m<<endl;
	return 0;
	
	
}
