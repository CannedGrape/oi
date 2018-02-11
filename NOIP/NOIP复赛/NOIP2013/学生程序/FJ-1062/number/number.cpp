#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;
int get(int a, int b){return a>0?a%b:-abs(a)%b;}
int abs(int a){return a>0?a:-a;}
int *spec, n, p, *stu, *score, m;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%d %d", &n, &p);
    spec=new int[n];
    stu=new int[n];
    score=new int[n];
    for(int i=0; i<n; i++) scanf("%d", &stu[i]);
    for(int i=0; i<n; i++) spec[i]=stu[i], score[i]=0;
    score[0]=stu[0];
    for(int i=0; i<n; i++){
        for(int j=0, t=0; j<=i; j++){
            t+=stu[j];
            if(t>spec[i]) spec[i]=t;
            if(t<0) t=0;
        }      
    }
    for(int i=1; i<n; i++) score[i]=score[i-1]+spec[i-1];
    m=score[0];
    for(int i=1; i<n; i++) if(score[i]>m) m=score[i];
    /*for(int i=0; i<n; i++) printf("%d ", spec[i]);
    printf("\n");
    for(int i=0; i<n; i++) printf("%d ", score[i]);
    printf("\n");*/
    printf("%d\n", get(m, p));
    return 0;
}
