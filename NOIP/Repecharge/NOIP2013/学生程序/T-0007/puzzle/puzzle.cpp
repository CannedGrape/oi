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
#define LOCAL
using namespace std;

#ifndef LOCAL
#define DEBUG
#endif

typedef unsigned long long int qword;
typedef long long int int64;

FILE * fin , * fout;

void Assign(){
    fin = stdin;
    fout = stdout;
    #ifdef DEBUG
    fin = fopen("puzzle.in" , "r");
    fout = fopen("puzzle.out" , "w");
    #endif  
}

int main(){
    Assign();
}
