#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
char kk[101];
int k[101],kt,t;
char m[1001],c[1001];
int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    cin.getline(kk,100);
    cin.getline(m,1000);
    t=strlen(m);
    kt=strlen(kk);
    int i;
    for (i=0;i<kt;i++)
    {
        if (kk[i]>='A' && kk[i]<='Z') k[i]=kk[i]-'A';
        else k[i]=kk[i]-'a';
    }
    i=0;
    int j=0;
    while (i<=t)
    {
        if (m[i]>='A' && m[i]<='Z')
        {
            c[i]=m[i]-k[j];
            if (c[i]<'A') c[i]+=26;
        }
        else
        {
            c[i]=m[i]-k[j];
            if (c[i]<'a') c[i]+=26;
        }
        i++;
        j=(j+1)%kt;
    }
    for (i=0;i<t;i++)
      cout<<c[i];
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
