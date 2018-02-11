#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX (100001)

struct numStack{
    int s[MAX];
    int top;
};

struct chaStack{
    char s[MAX];
    int top;
};

struct numStack a;
struct chaStack b;

/*=============================================================================*/
/*��ջ*/ 
void push(int x){
    a.s[a.top++]=x;
    return;
}
void push2(char c){
    b.s[b.top++]=c;
    return;
}

/*��ջ*/ 
int pop(){
    a.top--;
    return a.s[a.top];
}
char pop2(){
    b.top--;
    return b.s[b.top];
}
/*=============================================================================*/

int main() {
    char st[MAX];
    int pri[128],c;
    int i,x,len,flag;
    
    /*��ʼ��*/ 
    /*�������ȼ��ĳ�ʼ�� */
    memset(pri,0,sizeof(pri));
    pri['+']=1;
    pri['*']=2;
    a.top=b.top=0;
    
    /*freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);*/
     
    scanf("%s",st);
    len=strlen(st);
    
    for(i=x=0,flag=1;i<=len;){
        if(isdigit(st[i])){
            x*=10;
            x+=st[i]-'0';
        }
        else{
            if(flag){
                push(x);
                x=0;
            }
            /*printf("i:%d\tx:%d\n",i,x);*/
            
            /*ջ��Ԫ�ص����ȼ���*/ 
            if(pri[b.s[b.top-1]]<pri[st[i]] || b.top==0){
                push2(st[i]);
                if(flag==0)flag=1;
            }
            else{
                c=pop2();
                /*printf("%c\n",c);*/
                if(c=='+'){
                    push(pop()+pop());
                }
                if(c=='*') {
                    push(pop()*pop());
                }
                flag=0;
            }
        }
        if(flag)i++;
    }
    
    printf("%d",pop()%10000);
    
    return 0;
}
