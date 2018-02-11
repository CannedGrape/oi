#include <stdio.h>
#define FOR(i,a,b) for(int i = a;i <= b;++i)
using namespace std;

template <typename t> t MAX(t a,t b){return (a > b)?a:b;}

int n;
int hs[100001];
int f1[100001];
int f1a[100001];
int f2[100001];
int f2a[100001];
int Maxans;

int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&hs[i]);
    //FOR(i,1,n) f1[i] = f2[i] = f1a[i] = f2a[i] = 1;
    f1[1] = f2[1] = 1;
    f1a[1] = f2a[1] = hs[1];//hs[1];
    Maxans = 1;
    if (n >= 5000)
    {
    FOR(i,2,n)
    {
		f1[i] = f1[i-1];
		//f1a[i] = f1a[i - 1];
		f1a[i] = hs[i];
		f2[i] = f2[i-1];
		f2a[i] = hs[i];
		
		if (hs[i] > f1a[i-1] && f1[i - 1] % 2 == 1 &&f1[i] < f1[i - 1] + 1) f1a[i] = hs[i],f1[i] = f1[i - 1] + 1;
		if (hs[i] < f1a[i-1] && f1[i - 1] % 2 == 0 &&f1[i] < f1[i - 1] + 1) f1a[i] = hs[i],f1[i] = f1[i - 1] + 1;
		if (hs[i] > f1a[i-1] && f2[i - 1] % 2 == 0 &&f2[i] < f2[i - 1] + 1) f2a[i] = hs[i],f2[i] = f2[i - 1] + 1;
		if (hs[i] < f1a[i-1] && f2[i - 1] % 2 == 1 &&f2[i] < f2[i - 1] + 1) f2a[i] = hs[i],f2[i] = f2[i - 1] + 1;
		
        if (f1[i] > Maxans) Maxans = f1[i];
        if (f2[i] > Maxans) Maxans = f2[i];
    }
    }
    else
    {
    FOR(i,2,n)
    {
        FOR(j,1,i - 1)
        {
            if (f1[i] < f1[j] + 1)
            {
                if (hs[j] < hs[i] && f1[j] % 2 == 1) f1[i] = f1[j] + 1;
                if (hs[j] > hs[i] && f1[j] % 2 == 0) f1[i] = f1[j] + 1;
            }
            if (f2[i] < f2[j] + 1)
            {
                if (hs[j] < hs[i] && f2[j] % 2 == 0) f2[i] = f2[j] + 1;
                if (hs[j] > hs[i] && f2[j] % 2 == 1) f2[i] = f2[j] + 1;
            }
        }
        if (f1[i] > Maxans) Maxans = f1[i];
        if (f2[i] > Maxans) Maxans = f2[i];
    }
    }
    printf("%d",Maxans);
    //scanf("%*");
    return 0;
}
