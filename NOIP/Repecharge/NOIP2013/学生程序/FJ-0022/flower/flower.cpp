#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int N,i,j,k;
int h[100007];

inline void init()
{
       scanf("%d",&N);
       for (i = 1;i <= N;++i)
       {
           scanf("%d",&h[i]);
       }
}

inline void work()
{
       if (N <= 2) 
       {
             if (h[1] != h[2]) cout<<N<<endl;
             else cout<<1<<endl;
       }
       
       if (N == 3)
       {
             if ((h[2] > h[3]) && (h[2] > h[1])) cout<<3<<endl;
             else if ((h[2] < h[3]) && (h[2] < h[1])) cout<<3<<endl;
                  else cout<<2<<endl;
       }
       
       if (N == 4)
       {
             if ((h[2] > h[1]) && (h[2] > h[3]))
             {
                       if (h[4] > h[3]) cout<<4<<endl;
                       else cout<<3<<endl;
             }
             else if ((h[2] < h[1]) && (h[2] < h[3]))
                  {
                            if (h[4] < h[3]) cout<<4<<endl;
                            else cout<<3<<endl;
                  }
                  else if (((h[3] > h[2]) && (h[3] > h[4])) || ((h[3] < h[2]) && (h[3] < h[4])))
                       {
                                  cout<<3<<endl;
                       }
                       else
                       {
                           int tt;
                           for (i = 2;i <= 4;++i)
                           {
                               if (h[i] > h[i-1]) tt++;
                           }
                           if (tt == 4) cout<<2<<endl;
                           else cout<<3<<endl;
                       }
       }
       
}

int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    
    init();
    if (N <= 4) work();
    else cout<<N<<endl;
    
//    system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
