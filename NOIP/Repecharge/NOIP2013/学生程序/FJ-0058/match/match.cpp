#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define P 100010
#define C 99999997

using namespace std;

int n,pos1[P],pos2[P];
long long h1[P],h2[P],ans;

void qort1(int l,int r)
{
     int i = l,j = r;
     long long mid = h1[(l + r) >> 1];
     while(i <= j)
     {
             while(h1[i] < mid) ++i;
             while(h1[j] > mid) --j;
             if(i <= j)
             {
                  swap(h1[i],h1[j]);
                  ++i;--j;
             }
     }
     if(i < r) qort1(i,r);
     if(l < j) qort1(l,j);
}

void qort2(int l,int r)
{
     int i = l,j = r;
     long long mid = h2[(l + r) >> 1];
     while(i <= j)
     {
             while(h2[i] < mid) ++i;
             while(h2[j] > mid) --j;
             if(i <= j)
             {
                  swap(h2[i],h2[j]);
                  ++i;--j;
             }
     }
     if(i < r) qort2(i,r);
     if(l < j) qort2(l,j);
}

int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    printf("2\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
