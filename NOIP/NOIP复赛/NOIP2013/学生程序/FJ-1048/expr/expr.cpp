#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char *st;
char st2[10000][11],*st3;
int i,j,p,k,t,ans,n,d,sum;
int *a,*b;
int main() {  
    a=new int[100000];
    b=new int[100000];
    st=new char[1000000];
    st3=new char[10000];
    
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    
    gets(st);
    
    j=0;
    k=0;
    d=strlen(st);
    for(i=0;i<=d-1;i++) {                         
        if(st[i]>='0' && st[i]<='9') {
            st2[j][k]=st[i];
            k++;
        }
        else {
            st3[j]=st[i];
            j++;
            k=0;
        }
    }
    n=j;
    
    for(i=0;i<=n;i++) {
        p=1;
        d=strlen(st2[i]);
        for(k=0;k<=d-1;k++) p=p*10;
        p=p/10;
        sum=0;
        for(k=0;k<=d-1;k++) {
            sum=sum+(((int)(st2[i][k]-'0'))*p);
            p=p/10;
        }
        a[i]=sum;
    }
    
    j=0;
    for(i=0;i<=n;i++) {
        if(st3[i]=='*') {
            a[i+1]=a[i+1]*a[i];
            a[i]=-1;
        }
    }
    
    for(i=0;i<=n;i++) {
        if(a[i]!=-1) {
            b[j]=a[i];
            j++;
        }
    }
    
    ans=0;
    for(i=0;i<=j;i++) ans+=b[i];

    printf("%d",ans);
    
    fclose(stdin);
    fclose(stdout);

    return 0; 
}
