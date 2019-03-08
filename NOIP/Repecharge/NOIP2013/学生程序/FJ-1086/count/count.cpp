#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
int howMany(int n, int x){
    int cnt = 0;
    int bww, sww, xww, xqw, xbw, xsw, xgw;
    bww = n / 1000000;
    sww = (n - (bww * 1000000)) / 100000;
    xww = (n - (bww * 1000000) - (sww * 100000)) / 10000;
    xqw = (n - (bww * 1000000) - (sww * 100000) - (xww * 10000)) / 1000;
    xbw = (n - (bww * 1000000) - (sww * 100000) - (xww * 10000) - (xqw / 1000)) / 100;
    xsw = (n - (bww * 1000000) - (sww * 100000) - (xww * 10000) - (xqw / 1000) - (xbw / 100)) / 10;
    xgw = n % 10;
    if(bww == x) cnt++;
    if(sww == x) cnt++;
    if(xww == x) cnt++;
    if(xqw == x) cnt++;
    if(xbw == x) cnt++;
    if(xsw == x) cnt++;
    if(xgw == x) cnt++;
    return cnt;
}
int main(){
    ifstream fin;
    ofstream fout;
    fin.open("count.in");
    fout.open("count.out");
    int n, x, ans = 0;
    fin >> n >> x;
    for(int i = 1; i <= n; i++){
            ans += howMany(i, x);
    }
    fout << ans;
    fin.close();
    fout.close();
    return 0;
}
