#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int ans=0;
const int N=100011;
int h[N];
int n;

int main()
{
  freopen("block.in","r",stdin);
  freopen("block.out","w",stdout);
  scanf("%d",&n);
  for (int i=1;i<=n;i++) scanf("%d",&h[i]);
  h[0]=0;
  for (int i=1;i<=n;i++)
  {
    if (h[i]<=h[i-1]) continue;
    ans+=h[i]-h[i-1];
  }
  printf("%d\n",ans);
  return 0;
}
