#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>
ifstream fin1("zplhz.in");
ifstream fin2("zplhz.out");

int n, m;
int use[200];

struct Tpoint {
	double x, y;
};
Tpoint weapon[200];
Tpoint bomb[200];

double k;

void init()
{
	int i;

	fin1 >> m >> n >> k;
	for (i = 1; i <= m; i++)
		fin1 >> weapon[i].x >> weapon[i].y;
	for (i = 1; i <= n; i++)
		fin1 >> bomb[i].x >> bomb[i].y;
	k = k * k;
}

void error(char *s)
{
	cout << "Wrong Answer!" << endl;
//	cout << s << endl;
	exit(0);
}

void check()
{
	int i, j, now, ans;
	double g;

	memset(use, 0, sizeof(use));
	now = 1;
	fin2 >> ans;

	for (i = 0; i < ans; i++)
	{
		if (!(fin2 >> j)) error("Not enough number as you expect.");

		if (j < 1 || j > n) error("Invalid bomb number.");

		if (use[j] == 1)
			error("You've used one bomb more than twice.");

		use[j] = 1;

		while (now <= m)
		{
			g = (weapon[now].x-bomb[j].x)*(weapon[now].x-bomb[j].x)+(weapon[now].y-bomb[j].y)*(weapon[now].y-bomb[j].y);
			if (g <= k)	now++;
			else break;
		}
	}

	if (now <= m)
		error("You havn't destroyed all weapons.");

	cout << "OK! But it doesn't mean that you can get full score." << endl;
}

int main()
{
	init();
	check();
        return 0;
}
