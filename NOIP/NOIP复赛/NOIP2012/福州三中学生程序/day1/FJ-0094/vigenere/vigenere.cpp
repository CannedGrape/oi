#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    int i,lenk,lenm;
    string k,m;
    cin>>k>>m;
    lenk=k.length();
    lenm=m.length()-1;
    for(i=0;i<=lenm;i++)
      if(m[i]>='a'&&m[i]<='z')
      {
        if(k[i%lenk]>='A'&&k[i%lenk]<='Z')
          k[i%lenk]=k[i%lenk]-'A'+'a';
        if(m[i]-k[i%lenk]+'a'<'a')
          printf("%c",m[i]-k[i%lenk]+'z'+1);
        else
          printf("%c",m[i]-k[i%lenk]+'a');
      }
      else
      {
        if(k[i%lenk]>='a'&&k[i%lenk]<='z')
          k[i%lenk]=k[i%lenk]-'a'+'A';
        if(m[i]-k[i%lenk]+'A'<'A')
          printf("%c",m[i]-k[i%lenk]+'Z'+1);
        else
          printf("%c",m[i]-k[i%lenk]+'A');
      }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
