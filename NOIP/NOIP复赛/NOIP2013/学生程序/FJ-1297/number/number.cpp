#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	string s;
	ifstream fin("number.in");
	ofstream fout("numer.out");
	int n,p;
	fin>>n>>p;
	fin>>s;
	fout<<n<<endl;
	return 0;
}
