#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define MAX (20123)
struct con{
    bool stair;
    int aim;
};
con build[10001][101]={};
int i,j,n,m,start,k,sum=0;


int main(){
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    cin>>n>>m;
    for (i=1; i<=n; i++)
        for (j=0; j<m; j++)
            cin>>build[i][j].stair>>build[i][j].aim;
    cin>>start;
    i=1;j=start;
    k=0;
    sum=sum+build[i][start].aim;
    while (i<n && k<build[i][start].aim){   
        j++;
        if (build[i][j].stair==true) k++;
        if (k==build[i][start].aim){
            sum=sum+build[i+1][j].aim;
            i=i+1;
            start=j;
            k=0;
            continue;
        }
        if (j==m-1) j=0;
    }
    sum=sum%MAX;
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
