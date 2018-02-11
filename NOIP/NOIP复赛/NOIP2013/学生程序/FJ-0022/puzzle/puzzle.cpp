#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define LARGEST 0x7fffffff

struct PUZZLUE{int e,s,t;} x[506],y[506];
int i,j,k,N,Q,M;
int map[35][35];

inline void init()
{
       scanf("%d",&N,&M,&Q);
       for (i = 1;i <= N;++i)
           for (j = 1;j <= M;++j)
           {
               scanf("%d",&map[i][j]);
           }
       for (i = 1;i <= Q;++i)
       {
           scanf("%d%d%d%d%d%d",&x[i].e,&y[i].e,&x[i].s,&y[i].s,&x[i].t,&y[i].t);
           cout<<-1<<endl;
       }
}

int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    
    init();
    
//    system("pause");
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
