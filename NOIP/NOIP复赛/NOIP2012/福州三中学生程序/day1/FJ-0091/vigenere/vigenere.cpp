#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
#define MXLENTH1 110
#define MXLENTH2 1010
int lenthb,lenthc,ff=0;
char b[MXLENTH1],c[MXLENTH2],sb,sc,aa;
void solve()
{
     int tt=0;
     lenthb=strlen(b);lenthc=strlen(c);
     for (int i=0;i<=lenthc-1;i++)
       {
         if(c[i]>='A'&&c[i]<='Z')
           {
             ff=0;
             sc=c[i]-'A'+2;
           }
         else
          {ff=1;
           sc=c[i]-'a'+2;
          }
         if(b[tt]>='A'&&b[tt]<='Z')
           sb=b[tt]-'A'+1;
         else sb=b[tt]-'a'+1;
         if(sb<=sc) aa=sc-sb;
         else aa=sc+26-sb;
         //printf("%d %d %d\n",aa,sb,sc);
         if(ff==0)
          printf("%c",aa+'A'-1);
         else printf("%c",aa+'a'-1);
         tt++;
         if(tt==lenthb) tt=0;
       }
     printf("\n");
}
int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    
    scanf("%s\n%s\n",b,c);
    solve();
    
    fclose(stdin);fclose(stdout);
    return 0;
}
