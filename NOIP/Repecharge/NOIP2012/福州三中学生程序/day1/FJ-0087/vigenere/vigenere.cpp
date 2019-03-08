#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;
char ms[10001],ls;
char mw[10001],lw;

void init()
{
     cin>>ms;
	 cin>>mw;
     ls=strlen(ms),lw=strlen(mw);
}

//a:97 A:65

void work()
{
     int i;
     int t=ls-1,x,y,x1,y1,k;
     
     for(i=0;i<lw;i++){
     t=(t+1)%ls;
     x1=int(ms[t]),y1=int(mw[i]);
     if(x1>=97) x=97; else x=65;
     if(y1>=97) y=97; else y=65;
     k=( (y1-y)+(x-x1)+26 )%26+y;
     printf("%c",char(k));
     }
}

void print()
{
     printf("\n");
}

int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    
    init();
    work();
    print();
    
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
