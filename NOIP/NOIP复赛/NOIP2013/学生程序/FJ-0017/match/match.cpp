#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define ifn(x) if(!x)
using namespace std;
typedef long long ll;
const ll llinf=0x7fffffffffffffffll;
const int inf=0x3fffffff,upinf=0x7fffffff;
const double dinf=1e20,eps=1e-12;

const int mode=99999997;
int n;
int height1[100001],height2[100001],point1[100001],point2[100001];
void Init()
{
     scanf("%d",&n);
     rep(i,1,n) scanf("%d",&height1[i]);
     rep(i,1,n) scanf("%d",&height2[i]);
     rep(i,1,n) point1[i]=i;
     rep(i,1,n) point2[i]=i;
}
bool cmp1(const int x,const int y)
{
     return height1[x]>height1[y];
}
bool cmp2(const int x,const int y)
{
     return height2[x]>height2[y];
}
void Work()
{
     sort(point1+1,point1+n+1,cmp1);
     sort(point2+1,point2+n+1,cmp2);
     
     int ans=0;
     rep(i,1,n) {ans=(ans+abs(point1[i]-point2[i]))%mode; swap(height1[point1[i]],height1[point2[i]]);sort(point1+1,point1+n+1,cmp1);}
     printf("%d\n",ans);
}
int main()
{
    freopen("match.in","r",stdin); freopen("match.out","w",stdout);
    Init();
    Work();
    fclose(stdin); fclose(stdout);
    return 0;
}     
