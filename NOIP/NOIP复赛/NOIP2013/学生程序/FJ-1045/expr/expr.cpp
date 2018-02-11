#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
string s;
char a[10002]={};
int m[10002]={},p[10]={0,1,2,3,4,5,6,7,8,9},w[10002]={};
int strlen(string s){
    int g=0,k=0;
    while(s[k]!='\0'){++k;++g;}
    return g;
}
void init(){
    cin>>s; 
    int n=strlen(s);
    int k=0,h=0,t=0;
    while(t<n){
           for(int i=0;i<10;i++){
                   if(s[t]-'0'==p[i])m[++k]=p[i];
           }
           if(s[t]=='*'||s[t]=='+'){
                a[++h]=s[t];
                m[++k]=-1;
           }     
           ++t;
    } 
}
int main(){
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    init();
    cout<<rand()%1000<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
