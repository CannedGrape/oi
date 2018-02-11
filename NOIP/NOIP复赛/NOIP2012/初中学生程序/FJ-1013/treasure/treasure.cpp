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
const int MAXN = 10001;
const int MAXM = 101;
int n,m,nextt[MAXN][MAXM],numm[MAXN][MAXM],h[MAXN][MAXM],beginn,upnum[MAXN]={},anss=0;
void doing(int floor,int room)
{
    anss+=(numm[floor][room])%20123;
    anss%=20123; 
    int o=numm[floor][room],k;
    o%=upnum[floor];
    if(o == 0) o=upnum[floor];
    if(h[floor][room] == 1) k=room;
    else k=nextt[floor][room];
    for(int i=2;i<=o;++i){
        k=nextt[floor][k];
        //printf("%d %d %d\n",floor,i,k);
    }
    if(floor < n)
        doing(floor+1,k);
}
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    int q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        q=-1;
        for(int j=1;j<=m;++j){
            scanf("%d%d",&h[i][j],&numm[i][j]);
            if(h[i][j] == 1) upnum[i]++;
            if(h[i][j] == 1 && q == -1) q=j;
        }
        for(int j=m;j>=1;--j){
            if(h[i][j] == 1){
                nextt[i][j]=q;
                q=j;
            }else{
                nextt[i][j]=q;
            }
        }
    }
    scanf("%d",&beginn);
    doing(1,beginn+1);
    printf("%d\n",anss);
    fclose(stdin);
    fclose(stdout);
  //  system("pause");
    return 0;
}
