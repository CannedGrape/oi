#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
int n,k,m,s,t,
    c[101],dist[101][101],sumdist=0;
bool a[101][101];
int now,
    i,j,
    u,v,d;
    
void tryy(int now){
    int i;
    int head=0, tail=0;
    struct list{
        int nation;
        int pre; 
        int sumdist; 
    };
    list open[10001];
    memset(open,0,sizeof(open));
    open[head].nation=now;
    open[head].pre=0;
    do{
        head++;
        for (i=1; i<=n; i++){
            //判断条件：有路，对方不排斥我
            if (dist[open[head].nation][i]!=0 && a[i][open[head].nation]==false){
                tail++;
                open[tail].nation=i;
                open[tail].pre=head;
                open[tail].sumdist=open[head].sumdist+dist[i][now];
                a[i][open[head].nation]=true;
                if (open[tail].nation==t){
                    cout<<open[tail].sumdist<<endl;
                    fclose(stdin);
                    fclose(stdout);
                    exit(0);
                }
            }
        }
    }while(head<tail);
}    
int main(){
    freopen("culture.in","r",stdin);
    freopen("culture.out","w",stdout);
    memset(a,true,sizeof(a));
    memset(dist,0,sizeof(dist));
    cin>>n>>k>>m>>s>>t;
    for (i=1; i<=n; i++)
        cin>>c[i];
    for (i=1; i<=k; i++)
        for (j=1; j<=k; j++)
            cin>>a[i][j];
    for (i=1; i<=m; i++){
        cin>>u>>v>>d;
        dist[u][v]=d;
    }
    /*无解*/
    if (a[s][t]==true && a[t][s]==true){
        cout<<-1<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if (dist[s][t]!=0 || a[t][s]==false){
        sumdist=sumdist+dist[s][t];
        cout<<sumdist<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    /*有解*/
    now=s; //顺推
    tryy(now);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
