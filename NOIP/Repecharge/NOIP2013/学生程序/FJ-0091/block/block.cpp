#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 1000001;
int n,h[maxn],maxh,ans;
void input ()
{
     int i;
     scanf ("%d", &n);
     for (i=1; i<=n; i++)
     {
         scanf ("%d", &h[i]);
         maxh = max (h[i], maxh);
     }
}
void doing ()
{
     int i,j,minh,fir,en;
     bool flag;
     while (maxh>0)
     {
           flag = 0;
           minh = 9999999;
           maxh = 0;
           for (i=1; i<=n+1; i++)
           {
               if (h[i]==0 && flag==1)
               {
                     flag=0;
                     for (j=fir; j<=en; j++)
                     {
                         h[j]-=minh;
                         maxh =max (maxh, h[j]);
                     }
                     ans+=minh;
               }
               if (h[i])
               {
                  if (!flag)
                  {
                     flag=1;
                     fir=i;
                     en=i;
                     minh=h[i];
                  }
                  else
                  {
                      minh = min (minh, h[i]);
                      ++en;
                  }
               }
           }
     }
}
int main()
{
    freopen ("block.in", "r", stdin);
    freopen ("block.out","w",stdout);
    input ();
    doing ();
    cout<<ans;
    return 0;
}
