#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int N, M, K, X, P;

int qmi(int k)
{
	if(k == 0)
		return 1;
	if(k == 1)
		return 10;
	int t = qmi(k / 2) % P;
	return ((t % P) * (t % P) * (qmi(k % 2) % P)) % P;
}


int main()
{
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    scanf("%d%d%d%d", &N, &M, &K, &X);
    if(N % M == 0)
    	P = N / M;
    else
		P = N;
    int times = qmi(K) % P;
    for(int i = 1; i <= times; ++i)
		X = (X + M) % N;
	printf("%d\n", X);
    

    return 0;
}
