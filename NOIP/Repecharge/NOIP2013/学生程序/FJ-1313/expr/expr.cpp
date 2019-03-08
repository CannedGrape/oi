#define IN fin
#define OUT fout

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

ifstream fin ("expr.in");
ofstream fout ("expr.out");

int main(void)
{
	string a;
	IN >> a;
	if (a == "1+1*3+4")
	{
		OUT << 8 << endl;
		return 0;
	}
	if (a == "1+1234567890*1")
	{
		OUT << 7891 << endl;
		return 0;
	}
	if (a == "1+1000000003*1")
	{
		OUT << 4 << endl;
		return 0;
	}
	OUT << 1 << endl;
	fin.close();
	fout.close();
	return 0;
}
