#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
char key[110],p[1010];
int ans[1010]; 
int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    int i,j;
    int lenk,lenp;
    int pi,kj; 
    
    cin.getline(key,110,'\n');
    cin.getline(p,1010,'\n');
    lenk=strlen(key);
    lenp=strlen(p);
    i=0;j=0;
    while(i<=lenp)
    {
      pi=int(p[i]);
      kj=int(key[j]);
      if(65<=pi&&pi<=90)
      {
       if(65<=kj&&kj<=90)
       {  ans[i]=pi+1-kj;
          if(ans[i]<0) ans[i]+=26;
       }
       else
       {
         ans[i]=pi+1-(kj-32);
         if(ans[i]<0) ans[i]+=26;
       }
      }
      else
      {
       if(65<=kj&&kj<=90)
       {
         ans[i]=pi-32+1-kj;
         if(ans[i]<0) ans[i]+=26;
         ans[i]+=32;
       }
       else
       {
         ans[i]=pi-64+1-kj+64;
         if(ans[i]<0) ans[i]+=26;
         ans[i]+=32;
       }
      }
      i++;
      j=(j+1)%lenk;
    }
    for(i=0;i<=lenp;i++)
     printf("%c",char(ans[i]+64));
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
