#include <iostream>
using namespace std;

int mulku[100000];

long long int mul(long long int k,int n)
{
    long long int j;
    if (k == 0) return 1;
    if (k == 1) return 10;
    if (k < 100000 && mulku[k] != 0) return mulku[k];
    if (k % 2 == 1)
    {
          j = mul((k - 1) / 2,n);
          j = ((j * j) % n * 10) % n;
          if (k < 100000) mulku[k] = j;
          return j;
    }
    else
    {
        j = mul(k / 2,n);
        j = (j * j) % n;
        if (k < 100000) mulku[k] = j;
        return j;
    }
}

long long int dg(int n,int m,int k,int x)
{
    return (x + mul(k,n) * m) % n;
}

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int n,m,x;
    long long k;
    scanf("%d%d%lld%d",&n,&m,&k,&x);
    printf("%lld",dg(n,m,k,x));
    //scanf("%*");
	fclose(stdin);fclose(stdout);
    return 0;
}
