#define IN fin
#define OUT fout

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

ifstream fin ("count.in");
ofstream fout ("count.out");
long long n, x;
long long ans;
char num[10];

int main(void)
{
	IN >> n >> x;
	for (int i = 1; i <= n; ++i)
	{
		sprintf(num, "%d", i);
		int len (strlen(num));
		for (int j = 0; j < len; ++j)
		{
			if (num[j] - '0' == x)
				++ans;
		}
	}
	OUT << ans << endl;
	fin.close();
	fout.close();
	return 0;
}
