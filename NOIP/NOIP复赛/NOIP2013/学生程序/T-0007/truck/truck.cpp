#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FOT(i,a,b) for(int i=a;i>=b;--i)
#define MST(a,b) memset(a,b,sizeof(a))
#define MaxLongint 0x7fffffff
//#define LOCAL
using namespace std;

#ifndef LOCAL
#define DEBUG
#endif

int N,M,Q;
int List[7500][1000];
int G[7500][1000];
int Que[500000],Dis[7500];
bool Exist[10000];
int Xn[30000],Yn[30000];

template <typename Type>
Type Max(Type x,Type y){
    return x>y?x:y;
}

template <typename Type>
Type Min(Type x,Type y){
    return x<y?x:y;
}

int main(){
    #ifdef DEBUG
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    #define LOCAL
    #endif
    scanf("%d%d",&N,&M);
    FOR(i,1,M){
        int X,Y,Z;
        scanf("%d%d%d",&X,&Y,&Z);
        List[X][++List[X][0]]=Y;
        List[Y][++List[Y][0]]=X;
        G[X][List[X][0]]=G[Y][List[Y][0]]=Z;
    }
    scanf("%d",&Q);
    FOR(i,1,Q){
        int Head=0,Tail=1;
        scanf("%d%d",&Xn[i],&Yn[i]);
        if(Xn[i]==Xn[i-1]){
            if(Dis[Yn[i]]>=MaxLongint/3) printf("-1\n");
            else printf("%d\n",Dis[Yn[i]]);
            continue;
        }
        MST(Exist,true);
        MST(Dis,0);
        MST(Que,0);
        Que[1]=Xn[i],Exist[Xn[i]]=false,Dis[Xn[i]]=MaxLongint/3;
        do{
            int u=Que[++Head];
            Exist[u]=true;
            FOR(v,1,List[u][0]){
                int k=List[u][i],plus=G[u][i];
                if(Exist[k]&&Dis[k]<Min(Dis[u],plus)){
                    Exist[k]=false;
                    Que[++Tail]=k;
                    Dis[k]=Min(Dis[u],plus);
                }
            }
        }while(Head<Tail);
        if(Dis[Yn[i]]>=MaxLongint/3) printf("-1\n");
        else printf("%d\n",Dis[Yn[i]]);
    }
    //system("pause > nul");
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif 
    return 0;
}
