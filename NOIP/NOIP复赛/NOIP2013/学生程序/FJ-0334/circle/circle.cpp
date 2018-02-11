#include <cstdio>
#include <cstring>
typedef long long LL;
struct Matrix {
	int x, y;
	LL a[2][2];
	Matrix(const int _x = 2, const int _y = 2):
		x(_x), y(_y) { memset(a, 0, sizeof(a)); }
} A;
LL n, m, k, x, xh, tmp, mc;
inline Matrix operator*(const Matrix &a, const Matrix &b)
{
	Matrix c = Matrix(a.x, b.y);
	for (int i = 0; i < a.x; ++i)
		for (int k = 0; k < a.y; ++k)
			if (a.a[i][k] != 0)
				for (int j = 0; j < b.y; ++j)
					c.a[i][j] = (c.a[i][j] + a.a[i][k]*b.a[k][j]%n)%n;
	return c;
}
inline Matrix QuickPow(Matrix a, LL b)
{
	Matrix res;
	res.a[0][0] = res.a[1][1] = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = res*a;
		a = a*a;
	}
	return res;
}
inline LL Pow(LL a, LL b)
{
	LL res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = (res * a) % xh;
		a = (a * a) % xh;
	}
	return res;
}
int main()
{
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	
	scanf("%lld%lld%lld%lld", &n, &m, &k, &x);
	
	xh = 1;
	tmp = (x+m)%n;
	while (tmp != x) {
		++xh;
		tmp = (tmp+m)%n;
	}
	mc = Pow(10, k);
	Matrix f = Matrix(1, 2);
	f.a[0][0] = x, f.a[0][1] = m;
	A.a[0][0] = 1, A.a[0][1] = 0;
	A.a[1][0] = 1, A.a[1][1] = 1;
	printf("%lld\n", (f*QuickPow(A, mc)).a[0][0]);
}
