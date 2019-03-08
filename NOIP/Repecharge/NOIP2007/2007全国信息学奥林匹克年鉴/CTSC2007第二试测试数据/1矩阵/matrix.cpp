#include <cstdio>
#include <cmath>

#define InFile "matrix.in"
#define OutFile "matrix.out"

const			int				Limit			=		710;

const			int				LimitStep		=		15;

struct Tpoint {
	int x, y;
};

int A[Limit][Limit], T[Limit][Limit], ColD[Limit][Limit], RowD[Limit][Limit], blocked[Limit][Limit];
Tpoint queue[Limit * Limit];
int N, M, D, C;

void init()
{
	freopen(InFile, "r", stdin);
	scanf("%d%d%d%d", &C, &D, &N, &M);

	double pow = 1;
	if (C == 1)
	{
		for (int i = 0; i < LimitStep; i++) pow *= 2;
	}
	else
	{
		for (int i = 0; i < LimitStep; i++) pow *= 3;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			A[i][j] = int(round(pow * tmp / D));
		}
	}
}

void fill1(int i, int j)
{
	int open = 0, closed = 1;
	queue[0].x = i; queue[0].y = j; blocked[i][j] = 1;
	for (; open < closed; open++)
	{
		int x = queue[open].x, y = queue[open].y;
		if (RowD[x][y] != -1 && !blocked[x][RowD[x][y]])
		{
			queue[closed].x = x;
			queue[closed].y = RowD[x][y];
			closed ++;
			T[x][RowD[x][y]] = T[x][y] ^ 1;
			blocked[x][RowD[x][y]] = 1;
		}
		if (ColD[x][y] != -1 && !blocked[ColD[x][y]][y])
		{
			queue[closed].x = ColD[x][y];
			queue[closed].y = y;
			closed ++;
			T[ColD[x][y]][y] = T[x][y] ^ 1;
			blocked[ColD[x][y]][y] = 1;
		}
	}
}

void process1()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			T[i][j] = blocked[i][j] = 0;
			RowD[i][j] = ColD[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		int last = -1;
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] & 1)
			{
				if (last == -1)
				{
					last = j;
				}
				else 
				{
					RowD[i][last] = j;
					RowD[i][j] = last;
					last = -1;
				}
			}
		}
	}
	for (int j = 0; j < M; j++)
	{
		int last = -1;
		for (int i = 0; i < N; i++)
		{
			if (A[i][j] & 1)
			{
				if (last == -1)
				{
					last = i;
				}
				else
				{
					ColD[last][j] = i;
					ColD[i][j] = last;
					last = -1;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((A[i][j] & 1) && (!blocked[i][j]))
			{
				fill1(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			A[i][j] = A[i][j] / 2 + T[i][j];
		}
	}
}

void fill2(int i, int j2)
{
	int j1;
	for (j1 = j2 - 1; j1 >= 0 && A[i][j1] % 3 != 0; j1--);
	j1 ++; j2 --;

	if (j1 > j2) return;

	if ((A[i][j1] % 3 == A[i][j2] % 3) ^ ((j2 - j1) % 2 != 0))
	{
		if (A[i][j1] % 3 == 2) T[i][j1] = 1;
		for (int j = j1 + 1; j <= j2; j++) T[i][j] = 1 - T[i][j - 1];
		return;
	}
	int x1 = j1, x2 = j2 + 1, x3;
	int t1 = (A[i][j1] % 3 == 1 ? 0 : 1);
	for (x3 = j1 + 1; x3 <= j2; x3++)
	{
		int a = A[i][x3 - 1] % 3, b = A[i][x3] % 3;
		if (t1 == 0 && a == 1 && b == 1 || t1 == 1 && a == 2 && b == 2)
		{
			break;
		}
		t1 = 1 - t1;
	}

	int finalX = x1;
	if (i > 0 && blocked[i - 1][finalX] || i < N - 1 && blocked[i + 1][finalX])
	{
		finalX = x2;
	}
	if (i > 0 && blocked[i - 1][finalX] || i < N - 1 && blocked[i + 1][finalX])
	{
		finalX = x3;
	}
	T[i][j1] = (A[i][j1] % 3 == 1 ? 0 : 1);
	for (int j = j1 + 1; j <= j2; j++) T[i][j] = 1 - T[i][j - 1];
	for (int j = finalX; j <= j2; j++) T[i][j] = 1 - T[i][j];
	blocked[i][finalX] = 1;
}

void process2()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			T[i][j] = blocked[i][j] = 0;
		}
	}
	for (int j = M; j > 0; j--)
	{
		for (int i = 0; i < N; i++)
		{
			if (A[i][j] % 3 == 0)
			{
				fill2(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			A[i][j] = A[i][j] / 3 + T[i][j];
		}
	}
}

void work()
{
	for (int i = 0; i < LimitStep; i++)
	{
		if (C == 1)
		{
			process1();
		}
		else
		{
			process2();
		}
	}
}

void out()
{
	freopen(OutFile, "w", stdout);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d", A[i][j]);
			if (j < M - 1) printf(" ");
		}
		printf("\n");
	}
}

int main()
{
	init();
	work();
	out();
	return 0;
}