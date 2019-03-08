#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(int i = a;i <= b;++i)
using namespace std;

int   stk1_or[100001];
int   stk1_bk[100001];
int   stk2_or[100001];
int   stk2_bk[100001];
int   stk3[101];
string ts;

inline bool IsNum(char k){return (k >= '0' && k <= '9');}

inline void push_stack(int s[],int s2[],int end,int data)
{
     int* k;int f;
     k = s,++k[0],f = k[0];
     if (k[0] >= end) k = s2,f -= end;
     k[f] = data;
     return;
}

inline int top_stack(int s[],int s2[],int end)
{
     int* k;int f;
     k = s,f = k[0];
     if (k[0] >= end) k = s2,f -= end;
     return k[f];
}

int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    char t;
    cin >> ts;
    for(size_t i = 0;i <= ts.size() - 1;++i)
    {
        t = ts[i];
        if (IsNum(t))push_stack(stk3,NULL,101,t - '0');
        else
        {
            if (stk3[0] != 0)
            {
                int jjk = stk3[stk3[0]];
                if (stk3[0] > 1) jjk += stk3[stk3[0] - 1] * 10;
                if (stk3[0] > 2) jjk += stk3[stk3[0] - 2] * 100;
                if (stk3[0] > 3) jjk += stk3[stk3[0] - 3] * 1000;
                push_stack(stk1_or,stk1_bk,100001,jjk);
                stk3[0] = 0;
            }
            if (t == '+')
            while (stk2_or[0] != 0 && top_stack(stk2_or,stk2_bk,100001) == 2)
            {
                --stk2_or[0];
                int j = top_stack(stk1_or,stk1_bk,100001);
                --stk1_or[0];
                j = (j * top_stack(stk1_or,stk1_bk,100001)) % 10000;
                --stk1_or[0];
                push_stack(stk1_or,stk1_bk,100001,j);
            }
            push_stack(stk2_or,stk2_bk,100001,((t == '+')?1:2));
        }
    }
    int k,j;
    if (stk3[0] != 0)
    {
        int jjk = stk3[stk3[0]];
        if (stk3[0] > 1) jjk += stk3[stk3[0] - 1] * 10;
        if (stk3[0] > 2) jjk += stk3[stk3[0] - 2] * 100;
        if (stk3[0] > 3) jjk += stk3[stk3[0] - 3] * 1000;
        push_stack(stk1_or,stk1_bk,100001,jjk);
        stk3[0] = 0;
    }
    while (stk2_or[0] != 0)
    {
          k = top_stack(stk2_or,stk2_bk,100001);
          --stk2_or[0];
          if (k == 1)
          {
               j = top_stack(stk1_or,stk1_bk,100001);
               --stk1_or[0];
               j = (j + top_stack(stk1_or,stk1_bk,100001)) % 10000;
               --stk1_or[0];
               push_stack(stk1_or,stk1_bk,100001,j);
          }
          else
          {
               j = top_stack(stk1_or,stk1_bk,100001);
               --stk1_or[0];
               j = (j * top_stack(stk1_or,stk1_bk,100001)) % 10000;
               --stk1_or[0];
               push_stack(stk1_or,stk1_bk,100001,j);
          }
    }
    printf("%d",top_stack(stk1_or,stk1_bk,100001));
    fclose(stdin);fclose(stdout);
    return 0;
}
