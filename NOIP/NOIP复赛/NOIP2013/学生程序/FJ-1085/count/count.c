#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*计算数字x在n中出现的次数*/ 
int doCount(int n,int x){
    int count;
    for(count=0;n!=0;n/=10){
        if(n%10==x)count++;
    }
    return count;
}

int main() {
    int n,x,count;
    int i;
    
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    
    scanf("%d%d",&n,&x);
    /*printf("%d %d\n",n,x);*/
    
    for(i=1,count=0;i<=n;i++){
        count+=doCount(i,x);
        /*printf("%d\n",count); */
    }
    
    printf("%d",count);
    
    /*printf("%d",doCount(1111,1));*/
    
    return 0;
}
