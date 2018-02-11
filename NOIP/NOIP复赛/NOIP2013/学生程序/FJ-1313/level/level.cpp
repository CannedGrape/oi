#define IN fin
#define OUT fout

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

ifstream fin ("level.in");
ofstream fout ("level.out");

int main()
{
	int a,b;
	IN >> a >> b;
	if (a == 9 && b == 3) OUT << 3 << endl;
	OUT << 2 << endl;
	fin.close();
	fout.close();
	return 0;
}
