#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

char map[54][27],s1[101],s2[1001];
int a,c[1001],k[1001],lenk,lenc;

void per(void)
{
     map[1][1]='a';
     map[1][2]='z';
     for(int i=3;i<=26;i++)
       map[1][i]=map[1][i-1]-1;
     for(int i=2;i<=26;i++)
       for(int j=1;j<=26;j++)
         if(j==1)
           map[i][j]=map[i-1][26];
         else
           map[i][j]=map[i-1][j-1];
     map[27][1]='A';
     map[27][2]='Z';
     for(int i=3;i<=26;i++)
       map[27][i]=map[27][i-1]-1;
     for(int i=28;i<=52;i++)
       for(int j=1;j<=26;j++)
         if(j==1)
           map[i][j]=map[i-1][26];
         else
           map[i][j]=map[i-1][j-1];
     
}

int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    per();
    cin>>s1;
    lenk=strlen(s1);
    cin>>s2;
    lenc=strlen(s2);
    for(int i=1;i<=lenc;i++)
      if(s2[i-1]>='a')
        c[i]=s2[i-1]-96;
      else
        c[i]=s2[i-1]-38;
    
    for(int i=1;i<=lenc;i++)
      if(s1[(i-1)%lenk]>='a')
        k[i]=s1[(i-1)%lenk]-96;
      else
        k[i]=s1[(i-1)%lenk]-64;
    for(int i=1;i<=lenc;i++)
      cout<<map[c[i]][k[i]];
    
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
