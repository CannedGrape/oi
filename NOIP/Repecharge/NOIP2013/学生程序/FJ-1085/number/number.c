#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX (1000000)
#define IN (-0x7fffffff)

struct Child{
    int tz;                 /*特征值*/ 
    int mark;               /*分数*/ 
};

int main() {
    struct Child *s;
    int n,p;
    int i,j,temp,temp2,x;
    
    s=(struct Child*)malloc(MAX*sizeof(struct Child));
    
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    scanf("%d%d",&n,&p);
    for(i=0,x=IN;i<=n-1;i++){
        scanf("%d",&s[i].tz);
        if(s[i-1].tz>0 && i!=0){
           s[i].tz+=s[i-1].tz;
        }
        /*==================================*/
        if(i==0){
            s[i].mark=s[i].tz;
        }
        else{
            if(i==1){
                s[i].mark=s[i-1].mark+s[i-1].tz;
            }
            else{
                if(s[i-1].mark>0)s[i].mark=s[i-1].mark+s[i-1].tz;
                else s[i].mark=s[i-1].mark;
            }
        }
        if(s[i].mark>x)x=s[i].mark;
        /*printf("%d %d\n",s[i].tz,s[i].mark);*/
    
    }
    printf("%d",x%p);
    
    return 0;
}
