#include<iostream>
#include<stdio.h>
#define MAX (100)
using namespace std;
int main(){
    freopen("expr.in","r",stdin);
    freopen("expr.out" ,"w",stdout);
    
    char
       a[MAX];
    int
       s[MAX],
       b[MAX],
       i;
       
    cin.getline(a,100);
    
    for (i=0;i<=100;i++)
    {
        if (a[i]!='+' && a[i]!='*')
        s[i]=a[i];
    }
    
    cout<<s;
    
    system("pause");
    
    return 0;
}
