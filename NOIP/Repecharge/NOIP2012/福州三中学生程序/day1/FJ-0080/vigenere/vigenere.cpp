#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <string>
#include <cstring>
using namespace std;
char k[110],se[1010];
int q[110];
int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    scanf("%s\n%s\n",k,se);
    int i,j,lenk,lense,t;
    lenk=strlen(k);
    lense=strlen(se);
    j=0;
    for (i=0;i<lenk;i++)  
      if ('A'<=k[i] && k[i]<='Z') q[i]=k[i]-'A';
      else q[i]=k[i]-'a';
    for (i=0;i<lense;i++)
      {if ('A'<=se[i] && se[i]<='Z')
         {t=se[i]-'A';
          t-=q[j];
          if (t<0) t+=26;
          printf("%c",t+'A');
         }
       else
         {t=se[i]-'a';
          t-=q[j];
          if (t<0) t+=26;
          printf("%c",t+'a');
         }   
       j=(j+1)%lenk;
      }
    printf("\n");  
    fclose(stdin);
    fclose(stdout);
    return 0;
}
