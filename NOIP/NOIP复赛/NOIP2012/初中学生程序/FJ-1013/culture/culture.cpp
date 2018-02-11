#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
int n,k,m,s,t,wh[101],nott[101][101]={},edges[101][101]={},nanss=0,anss=2147483647;
bool c[101]={};
inline bool pd(int a){
    for(register int i=1;i<=n;++i){
        if(nott[a][i] == 1 && c[i] == 1) return false;
    }
    return true;
}
void tryy(int noww)
{
    for(register int i=1;i<=n;++i){
        if(c[wh[i]] == 0 && edges[noww][i] != 0 && pd(i) == true){
            nanss+=edges[noww][i];
            c[wh[i]]=1;
            if(i == t && nanss < anss) anss=nanss;
            else tryy(i);
            c[wh[i]]=0;
            nanss-=edges[noww][i];
        }
    }
}
int main()
{
    freopen("culture.in","r",stdin);
    freopen("culture.out","w",stdout);
    register int u,v,d;
    scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
    for(register int i=1;i<=n;++i) scanf("%d",&wh[i]);
    for(register int i=1;i<=k;++i){
        for(register int j=1;j<=k;++j) scanf("%d",&nott[i][j]);
    }
    for(register int i=1;i<=m;++i){
        scanf("%d%d%d",&u,&v,&d);
        if(edges[u][v] == 0 || edges[u][v] > d){
            edges[u][v]=d;
            edges[v][u]=d;
        }
        //if(edges[v][u] == 0 || edges[v][u] > d)    
    }
    c[wh[s]]=1;
    tryy(s);
    if(anss != 2147483647)
        printf("%d\n",anss);
    else
        printf("-1\n");
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
