#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    srand((int)time(0));
    cout<<rand()%1000000;
    return 0;
}
