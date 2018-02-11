#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define P 1000010

using namespace std;

int n,m,x,k,pos,tot;
int xs[P];

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int i,j;
    scanf("%d%d%d%d",&n,&m,&k,&x);
    xs[0] = 1;
    xs[1] = (x + m) % n;
    j = (xs[1] + m) % n;
    while(j != xs[1])
    {
            xs[++xs[0]] = j;
            j = (j + m) % n;
    }
    tot = xs[0];
    k %= tot;
    pos = 1;
    for(i = 1;i <= k;i++) pos = (pos * 10) % tot; 
    if(pos == 0)printf("%d\n",xs[xs[0]]);
    else printf("%d\n",xs[pos]);
    fclose(stdin);
    fclose(stdout);
    return 0;      
}
