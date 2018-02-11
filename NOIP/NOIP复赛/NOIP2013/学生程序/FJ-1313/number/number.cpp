#define IN fin
#define OUT fout

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

ifstream fin ("number.in");
ofstream fout ("number.out");

int n, p;
long long num[10010], id[10010], s[10010];

int main()
{
	IN >> n >> p;
	for (int i = 0; i < n; ++i) IN >> num[i];
	for (int a = 0; a < n; ++a)
	{
		int m(-10000000);
		for (int i = 0; i <= a; ++i)
			for (int j = i; j <= a; ++j)
			{
				int b(0);
				for (int z = i; z <= j; ++z)
					b = b % p + num[z] % p;
				m = max(b, m);
			}
		id[a] = m;
	}
	s[0] = id[0];
	for (int i = 1; i < n; ++i)
	{
		s[i] = -10000000;
		for (int j = 0; j < i; ++j)
		{
			s[i] = max((id[j] % p + s[j] % p) % p, s[i]);
		}
	}
	sort(s, s+n);
	OUT << s[n - 1] % p << endl;
	fin.close();
	fout.close();
	return 0;
}
