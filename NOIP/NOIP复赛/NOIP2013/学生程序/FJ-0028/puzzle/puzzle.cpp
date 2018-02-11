#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <memory.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N = 30,geps = 10;
int n,m,q,mapp[N+geps][N+geps],movex[5]={0,0,0,1,-1},movey[5]={0,1,-1,0,0};
int ex,ey,sx,sy,tx,ty;
void Init(){
    scanf("%d%d%d",&n,&m,&q);
    rep(i,1,n)
        rep(j,1,m){
            scanf("%d",&mapp[i][j]);
        }
}
map<int,int>_h;
map<int,bool>_h2;
inline int h(int a,int b,int c,int d){
    return _h[a*31*31*31+b*31*31+c*31+d];
}
inline bool h2(int a,int b,int c,int d){
    return _h2[a*31*31*31+b*31*31+c*31+d];
}
inline void make_h(int a,int b,int c,int d,int k){
    _h[a*31*31*31+b*31*31+c*31+d]=k;
}
inline void make_h2(int a,int b,int c,int d){
    _h[a*31*31*31+b*31*31+c*31+d]++;
}
int tryy(int _ex,int _ey,int _sx,int _sy,int lex,int ley){
    int a=h(_ex,_ey,_sx,_sy);
    if(a == -1) return a;
    if(h2(_ex,_ey,_sx,_sy) > n*n) return -1;
    if(_sx == tx && _sy == ty){
        make_h(_ex,_ey,_sx,_sy,-2); 
        return -2;
    }
    make_h2(_ex,_ey,_sx,_sy);
    int b,d=0;
    if(a == 0) a=2147483647;
    rep(i,1,4){
        int newx=_ex+movex[i],newy=_ey+movey[i];
        if(mapp[newx][newy] != 0 && (newx != lex || newy != ley)){
            if(newx == _sx && newy == _sy){
                b=tryy(_sx,_sy,_ex,_ey,_ex,_ey);
                if(b != -1){
                     if(b == -2) b=0;
                     a=min(a,b);
                }else d++;
            }else{
                b=tryy(newx,newy,_sx,_sy,_ex,_ey);
                if(b != -1){
                     if(b == -2) b=0;
                     a=min(a,b);
                }else d++;
            }
        }else d++;
    }
    if(d == 4){
        make_h(_ex,_ey,_sx,_sy,-1);
        return -1;    
    }else{
        make_h(_ex,_ey,_sx,_sy,a+1);
        return a+1;    
    }
}
void Solve(){
    Init();
    rep(i,1,q){
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        printf("%d\n",tryy(ex,ey,sx,sy,-1,-1));
    }
}
int main(){
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    Solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
