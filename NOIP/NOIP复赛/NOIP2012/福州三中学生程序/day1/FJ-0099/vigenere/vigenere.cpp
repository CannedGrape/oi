#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
char k[101],v[1001];
int lk,lv,i,j;
int main()
{   freopen("vigenere.in","r",stdin);freopen("vigenere.out","w",stdout);
    scanf("%s %s",&k,&v);
    lk=strlen(k);lv=strlen(v);
    for(i=0;i<=lk-1;i++)
      {if(k[i]>=97)k[i]=k[i]-97;
       else k[i]=k[i]-65;
      }
    i=0;j=0;
    while(j<lv)
      {i=i%lk;
       if(v[j]>=97&&v[j]<=122)
         printf("%c",(v[j]-97-k[i]+26)%26+97);
       else printf("%c",(v[j]-65-k[i]+26)%26+65);
       i++;j++;
      }
    printf("\n");
    fclose(stdin);fclose(stdout);
    return 0;
}
