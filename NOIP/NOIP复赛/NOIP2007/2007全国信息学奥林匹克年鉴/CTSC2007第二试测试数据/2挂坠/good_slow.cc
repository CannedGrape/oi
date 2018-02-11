#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const	int		limitSize	= 1000000 + 10;
const	long long	infinity	= (long long) 1 << 62;

struct			Tdat
{
	long long	cap , weight;
};

bool	operator < (const Tdat& A , const Tdat& B)
{
	return A.cap + A.weight < B.cap + B.weight;
}

int			n;
Tdat			list	[limitSize];

void	init()
{
	int		i;
	int		c , w;
	scanf("%d" , &n);
	for(i = 0; i < n; i ++)
	{
		scanf("%d%d" , &c , &w);
		list[i].cap = c;
		list[i].weight = w;
	}

	sort(list , list + n);
}

int			L;
long long			opt	[limitSize];

void	solve()
{
	L = 0;
	opt[0] = 0;

	int		i , p , r , m;
	for(i = 0; i < n; i ++)
	{
		opt[L + 1] = infinity;
		p = 0; r = L + 1;
		while(p + 1 < r)
		{
			m = (p + r) / 2;
			if( opt[m] <= list[i].cap ) p = m;
			else r = m;
		}

		for(; p >= 0; p --)
		{
			if( opt[p] + list[i].weight <= opt[p + 1] )
				opt[p + 1] = opt[p] + list[i].weight;
			else break;
		}
		if( opt[L + 1] < infinity / 2 ) L ++;
	}

	cout << L << endl;
	cout << opt[L] << endl;
}

int	main()
{
	freopen("pendant.in" , "r" , stdin);
	freopen("pendant.out" , "w" , stdout);

	init();
	solve();

	return 0;
}
