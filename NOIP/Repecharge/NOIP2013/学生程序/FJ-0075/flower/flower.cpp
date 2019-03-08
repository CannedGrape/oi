#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int N,h[100010]={},f[100010][2],F[100010][2];
int Max(int a,int b){
    if(a>b)return a;return b;
}
int main(){
    freopen("flower.in","r",stdin);freopen("flower.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;++i)scanf("%d",&h[i]);
    f[1][0]=F[1][0]=0;f[1][1]=F[1][1]=1;
    for(int i=2;i<=N;++i){
            f[i][0]=F[i][0]=0;f[i][1]=F[i][1]=1;
            for(int j=1;j<=i-1;++j){
                    if(h[i]>h[j]){
                        F[i][1]=max(F[i][1],F[j][0]+1);
                        f[i][0]=max(f[i][0],f[j][1]+1);
                    }
                    else if(h[i]<h[j]){
                        F[i][0]=max(F[i][0],F[j][1]+1);
                        f[i][1]=max(f[i][1],f[j][0]+1);
                        }
            }
    }
    int ans=-0x7fffffff;
    for(int i=1;i<=N;++i){
            ans=Max(ans,Max(Max(F[i][0],f[i][0]),Max(F[i][1],f[i][1])));
//            cout<<i<<"ou<ji : on ji "<<F[i][1]<<" on ou "<<F[i][0]<<endl;
//            cout<<i<<"ou>ji : on ji "<<f[i][1]<<" on ou "<<f[i][0]<<endl;
//            cout<<endl;
            }
//    cout<<f[N]<<" "<<F[N]<<endl;
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
//    system("pause");
    return 0;
}
