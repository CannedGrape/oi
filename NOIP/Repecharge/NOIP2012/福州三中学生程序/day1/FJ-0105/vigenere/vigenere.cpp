#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    int m,n,k,i,la,lb,j=0,q=0;
    char a[101]={},b[1001]={},c[1001]={},d[3]={'0','A','a',};
    cin.getline(a,101);
    cin.getline(b,1001);
    la=strlen(a);
    lb=strlen(b);
    if(lb<=la)
     for(i=0;i<=lb-1;i++)
       {//if(b[i]<97 && a[i]<97)
          c[i]=a[i]+b[i]-d[1];
        /*if(b[i]>97 && a[i]<97)
          c[i]=a[i]+32+b[i]-d[2];
        if(b[i]<97 && a[i]>97)
          c[i]=a[i]-32+b[i]-d[1];
        if(b[i]>97 && a[i]>97)
          c[i]=a[i]+b[i]-d[2];*/
        cout<<c[i];
        }
     if(lb>la)
       {m=lb/la;
        n=lb%la;
        for(i=1;i<=m;i++)
         {if(i==1)
            for(k=0;k<=la-1;k++)
              {//if(b[k]>=97)
               c[k]=a[k]+b[k]-d[1];
               cout<<c[k];}
          else
            for(k=(i-1)*la;k<=i*la-1;k++)
              {//if(b[k]>=97)
               c[k]=a[j]+b[k]-d[1];
               cout<<c[k];
               j++;}
          }
         for(i=0;i<=n-1;i++)
           {c[m*la+i]=a[i]+b[m*la+i]-d[1];
            cout<<c[m*la+i];
            }
       }   
     fclose(stdin);
     fclose(stdout);
     //system("pause");
     return 0;
}        
         
    
