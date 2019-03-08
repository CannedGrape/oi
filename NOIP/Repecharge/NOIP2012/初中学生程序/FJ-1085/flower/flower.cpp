#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define MAX (1000007)
int n,m,i;
long long total=0;
int a[101],arrange[101],sum_f[101];


void check(){
    int i;
    for (i=1; i<=n; i++)
        if (sum_f[i]==0) return;
    for (i=1; i<m; i++)
        if (arrange[i]>arrange[i+1]) return; 
    total++;
}
int judge(int pos){
    int i,len=m-pos+1,sum=0;
    for (i=n; i>=1; i--){
        sum=sum+a[i];
        if (sum>=len){ 
            return i; 
        }   
    }
}
void tryy(int pos,int flower){
    int i;
    
    
    for (i=flower; i<=judge(pos); i++){
        
        if (a[i]>sum_f[i]){ //第flower种花还没放完
            arrange[pos]=i;
            
            sum_f[i]++;
            
            if (pos==m-1) {
                check(); 
                
            }
            
            else{
                if (sum_f[i]==a[i])
                    tryy(pos+1,flower+1);
                else
                    tryy(pos+1,flower); 
            }
            
            sum_f[i]--;
            
        } 
    }
}



int main(){
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    memset(sum_f,0,sizeof(sum_f));
    
    cin>>n>>m;
    for (i=1; i<=n; i++) {cin>>a[i];}
    arrange[1]=1; arrange[m]=n;
    sum_f[1]=1; sum_f[n]=1;
    tryy(2,1);
    cout<<total%MAX<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
