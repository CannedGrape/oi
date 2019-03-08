#include<cstdio>
#include<iostream>
using namespace std;
char a;
int num[1000002],sum,n=1,l;
int main(){
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    scanf("%d%c",&num[1],&a);
    while(a!='\n'){
           if (a=='*') {
               scanf("%d",&l);
               num[n]*=l;
               scanf("%c",&a);
           }
           else scanf("%d%c",&num[++n],&a);
    }       
    for (int i=1; i<=n; i++)sum+=num[i];
    printf("%d",sum%10000);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
      
