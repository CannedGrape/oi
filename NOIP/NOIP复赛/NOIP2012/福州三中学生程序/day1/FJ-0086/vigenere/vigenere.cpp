#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#define MXSUB 110
#define MXSTR 1010
using namespace std;
char sub[MXSUB],str[MXSTR],aim[MXSTR];
int lsub,lstr;
void init()
{
     scanf("%s%s",sub,str);
     lsub=strlen(sub);
     lstr=strlen(str);
}
void solve()
{
     for (int i=0;i<lsub;i++)
     {
       if (sub[i]>='a'&&sub[i]<='z')  sub[i]-='a';
       else if (sub[i]>='A'&&sub[i]<='Z')  sub[i]-='A';
     }  
     for (int i=0,j=0;i<lstr;i++,j=(j+1)%lsub)
     {
       if ('A'<=str[i]&&str[i]<='Z')  
       {
         aim[i]=str[i]-'A'-sub[j];
         if (aim[i]<0)  aim[i]+=26;
         aim[i]+='A';
       }
       else if ('a'<=str[i]&&str[i]<='z')
       {
         aim[i]=str[i]-'a'-sub[j];
         if (aim[i]<0)  aim[i]+=26;
         aim[i]+='a';
       }
     }
     aim[lstr]=0;
}
int main ()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    init();
    solve();
    printf("%s\n",aim);
    fclose(stdin);fclose(stdout);
    return 0;
}
