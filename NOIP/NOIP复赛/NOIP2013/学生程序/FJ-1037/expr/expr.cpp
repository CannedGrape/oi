#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FOT(i,a,b) for(int i=a;i>=b;--i)
#define MST(a,b) memset(a,b,sizeof(a))
#define MaxLongint 0x7fffffff
#define Max 1000000 + 1000
//#define LOCAL
using namespace std;

#ifndef LOCAL
#define DEBUG
#endif

string Qem;
unsigned long long Answer=0,R,L=0;

struct stack{
    int Top;
    int Number[Max];
    stack(){
        memset(Number,0,sizeof(Number));
        Top=0;
    }
    int top(){return Number[Top];}
    void push(int x){Number[++Top]=x;}
    void pop(char ch){      
        switch(ch){
            case '+':
                Answer+=Number[Top--];
                Answer%=10000;
                break;
            case '*':
                int mul=Number[Top--];
                mul*=Number[Top--];
                push(mul);
                break;
        }        
    }
}s;

int main(){
    #ifdef DEBUG
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    #define LOCAL
    #endif
    getline(cin,Qem);
    Qem+='+';
    FOR(i,1,Qem.size()-1){
        if(Qem[i]=='+'||Qem[i]=='*'){
            string N=Qem.substr(L,i-L);
            sscanf(N./*substr(N.size()-4,4).*/c_str(),"%lld",&R);
            s.push(R%10000);
            L=i+1;
        }
    }
    Qem='+'+Qem;
    FOT(i,Qem.size()-2,0){
        if(Qem[i]=='+'||Qem[i]=='*'){
            s.pop(Qem[i]);
        }
    }
    printf("%lld\n",Answer);
    //system("pause > nul");
    #ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
