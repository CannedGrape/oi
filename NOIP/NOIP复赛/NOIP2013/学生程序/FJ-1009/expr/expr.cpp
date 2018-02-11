#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<cstring>
using namespace std;
int sm[100001];
long long sz[100001];
char c[100001];
long long sec[100001];
long long tot=0;
void init()
{
     int i=1;
     while(scanf("%d%c",&sm[i],&c[i])!=EOF)
       i++;
     i--;
     for(int j=1;j<=i;j++)
       sz[j]=sm[j];
     long long Ug,mt;
     Ug=-1;
     mt=1;
     c[i]='+';
     for(int j=1;j<=i;j++)
     {
       if(c[j]=='+')
       {
         if(Ug==-1)
           sec[mt]=sz[j];
         else
           sec[mt]=Ug;
         Ug=-1;
         mt++;
       }
       if(c[j]=='*')
       {if(Ug==-1){Ug=sz[j];Ug=(Ug*sz[j+1])%10000;}else{Ug=(Ug*sz[j+1])%10000;}}
     }    
     for(int j=1;j<mt;j++)
       tot=(tot+sec[j])%10000;
     cout<<tot<<endl;
}  
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    init();
    //system("pause");
    return 0;
}
     
