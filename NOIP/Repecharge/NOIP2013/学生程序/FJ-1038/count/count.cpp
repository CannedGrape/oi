#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#define MAX (10)
using namespace std;
char a[MAX];
int w,x,i;
/*void count(int b[],int c){
    sort(b,b+w);
    if( a[0]<x  || a[w-1]>x )
        count()
    else{
        for(i=0;i<=w;i++)
        
        
    }
}*/
int main(){
    long long n;
    int i,y;
    
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    
    cin>>n;
    cin>>x;
    y=0;
    for(i=x;i<=n;i+=10)
        while(i!=0){
           if(i%10==x){
               i=i/10;
               y++;
           }
    }
  /*  y=0;
    for(i=0;i<w;i++)    
        if(a[i]==x)
            y++;  */      
    cout<<y+1<<endl;
    
    
    
    fclose(stdin);
    fclose(stdout);
    return 0;    
}
