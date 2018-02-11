#include <cstdio>
#include <cstring>
#include <cstdlib>

FILE	*fin , *fout , *fans;

long long	vL , vW;
long long	L , W;

void	getInt( long long& x , FILE *f )
{
	char	str	[1000];
	fscanf(f , "%s" , str);

	x = 0;
	for(int i = 0; str[i]; i ++)
	{
		if( i > 15 ) return;
		x = x * 10 + str[i] - '0';
	}
}

void	score(const char *msg , int score)
{
	freopen("/tmp/_eval.score" , "w" , stdout);
	printf("%s\n%d\n" , msg , score);

	exit(0);
}

void	init()
{
	getInt( L , fans );
	getInt( W , fans );

	getInt( vL , fout );
	getInt( vW , fout );
}

void	solve()
{
	if( L == vL )
	{
		if( W == vW )
			score("Correct Answer!!!" , 10);
		else	score("Correct L , but Incorrect W." , 4);
	}
	else
	{
		score( "Incorrect L." , 0 );
	}
}

int	main(int argc, char *argv[])
{
	fin	= fopen( argv[1] , "r" );
	fout	= fopen( argv[2] , "r" );
	fans	= fopen( argv[3] , "r" );

	if( fin == NULL || fout == NULL || fans == NULL )
	{
		score( "No Output File" , 0 );
	}

	init();
	solve();

	return 0;
}
