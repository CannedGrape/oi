#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <deque>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FOT(i,a,b) for(int i = a; i >= b; --i)
#define MST(a,b) memset(a , b , sizeof(a))
#define MaxLongint 0x7fffffff
#define MaxArray 100000 + 100
//#define LOCAL
using namespace std;

#ifndef LOCAL
#define DEBUG
#endif

typedef unsigned long long int qword;
typedef long long int int64;

struct block{
    bool Over;
    qword High;
    qword Now;
    block(){Over = High = Now = 0;}
};

block Array[MaxArray];
int N , Answer = 0;
bool Flag = false;

void push(int l , int r){
    FOR(i,l,r){
        if(!Array[i].Over) ++Array[i].Now;
        if(Array[i].Now==Array[i].High) Array[i].Over = true;
    }
}

void BugExit(){
    bool B1 = true , B2 = true;
    qword Max = Array[1].High;
    FOR(i,2,N){
        if(Array[i].High > Array[i-1].High) B1 = false;
        if(Array[i].High <= Array[i-1].High) B2 = false;
        if(!B1 && !B2) break;
        Max = max(Max , Array[i].High);
    }
    if(B1 || B2){
        cout<<Max<<endl;
        //system("pause > nul");
        fclose(stdin);
        fclose(stdout);
        exit(0);
    }
}

int main(){
    #ifdef DEBUG
    freopen("block.in" , "r" , stdin);
    freopen("block.out" , "w" , stdout);
    #endif
    scanf("%d" , &N);
    FOR(i,1,N){ 
        qword X;
        cin>>X;
        Array[i].High = X;
        if(!X) Array[i].Over = true;
    }
    BugExit();
    while(!Flag){
        Flag = true;
        FOT(i,N,1){
            if(!Array[i].Over){
                bool Result = false;
                FOR(j,1,i){
                    loop :
                    if(!Array[j].Over){
                        Result = true;
                        FOR(k,j+1,i-1){
                            if(Array[k].Over){
                                Result = false;
                                break;
                            }
                        }
                        if(Result){
                            push(j,i);
                            ++Answer;
                            goto loop;
                        }
                    }
                }
            }
            if(!Array[i].Over) Flag = false;
        }
    }
    printf("%d\n" , Answer);
    //system(" pause > nul");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
