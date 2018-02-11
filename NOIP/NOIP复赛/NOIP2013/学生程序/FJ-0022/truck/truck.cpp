#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
#define LARGEST 0x7fffffff

struct EDGE{int start,end,weight;} edge[50007],q[30007];
bool intree[10007] = {};
int map[1007][1007];
int i,j,k,N,M,Q,ans;

bool cmp(EDGE A,EDGE B)
{
     return A.weight>B.weight;
}

int dfs(int s,int EnD)
{
    int ii,XX = LARGEST,YY = 0;
    for (ii = 1;ii <= N;++ii)
    {
        if (map[s][ii] > 0)
        {
                      if (ii == EnD) 
                      {
//                             cout<<"!!";
                             return map[s][ii];
                      }
                      else 
                      {
                           XX = min(dfs(ii,EnD),map[s][ii]);
//                           cout<<XX<<endl;
                      }
                      YY = max(YY,XX);
        }
    }
    return YY;
}

inline void init()
{
       scanf("%d%d",&N,&M);
       for (i = 1;i <= M;++i)
       {
           scanf("%d%d%d",&edge[i].start,&edge[i].end,&edge[i].weight);
       }
       scanf("%d",&Q);
       for (i = 1;i <= Q;++i)
       {
           scanf("%d%d",&q[i].start,&q[i].end);
       }
       sort(edge+1,edge+N+1,cmp);
}


inline void kruscal()
{
       for (i = 1;i <= M;++i)
       {
           if ((intree[edge[i].start] == false) || (intree[edge[i].end] == false))
           {
                           map[edge[i].start][edge[i].end] = map[edge[i].end][edge[i].start] = edge[i].weight;
                           intree[edge[i].start] = intree[edge[i].end] = true;             
           }
       }
}

int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    
    init();
    kruscal();
       
    for (i = 1;i <= Q;++i)
    {
        if ((!intree[q[i].start]) || (!intree[q[i].end]))
        {
                                  cout<<-1<<endl;
        }
        else 
        {
             ans = dfs(q[i].start,q[i].end);
             cout<<ans<<endl;
        }
    }
    fclose(stdin); fclose(stdout);
//    system("pause");
    return 0;
}


/*

4 3
1 2 4
2 3 3
3 1 1
3
1 3
1 4
1 3


6 7
1 3 7
3 4 2
1 4 6
4 1 3
2 3 1
1 6 5
4 5 2
5
1 2
1 4
4 6
2 4
4 5

*/
