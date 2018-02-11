#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
char k[100]={},c[1000]={},m[1000]={};
int lk,lc,mima[101]={};
void change()
{int i;
 for (i=1;i<=lk;i++)
     {if (65<=k[i-1]&&90>=k[i-1])
         mima[i]=int(k[i-1])-65;
      else
         mima[i]=int(k[i-1])-97;
     }
}
void print()
{int i,j=1;
 for (i=0;i<=lc-1;i++)
     {if (j>lk)
         j-=lk;
      int a=int(c[i])-mima[j];
      if (65<=c[i]&&90>=c[i]&&a<65)
         a+=26;
      else
         if (97<=c[i]&&122>=c[i]&&a<97)
            a+=26;
      m[i]=char(a);
      j++;
     }
 printf("%s\n",m);
}
int main()
{freopen ("vigenere.in","r",stdin);
 freopen ("vigenere.out","w",stdout);
 scanf("%s %s",&k,&c);
 lk=strlen(k);lc=strlen(c);
 change();
 print();
 fclose(stdin);
 fclose(stdout);
 return 0;
}
