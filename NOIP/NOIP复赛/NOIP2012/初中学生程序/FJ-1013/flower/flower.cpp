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
int n,m,a[101],f[101][101]={},anss=0;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=n;++i){
        f[i][1]=i;
        f[i][0]=1;
    }
    for(int i=1;i<=a[1];++i){
        f[1][i]=1;
        //f[0][i]=1;
    }
    for(int i=2;i<=n;++i){
        for(int j=2;j<=m;++j){
            for(int k=0;k<=a[i];++k){
                if(j >= k){
                    f[i][j]+=(f[i-1][j-k]);
                    f[i][j]%=1000007;
                }
            }
        }
    }
    printf("%d\n",f[n][m]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
