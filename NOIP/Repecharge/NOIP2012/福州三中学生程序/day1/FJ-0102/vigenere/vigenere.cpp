#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
char k[101],a[1001];
int lenk,lena,i,j;
int main(){
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    cin.getline(k,100);
    cin.getline(a,1000);
    lenk=strlen(k);lena=strlen(a);
    for(i=0;i<lenk;i++)if(k[i]<97)k[i]+=32;
    j=0;
    for(i=0;i<lena;i++){
      if(a[i]>=97){
        if(a[i]>=k[j])a[i]=a[i]-(k[j]-97);
        else a[i]=a[i]+26-(k[j]-97);}
      else{
        if(a[i]+32>=k[j])a[i]=a[i]-(k[j]-97);
        else a[i]=a[i]+26-(k[j]-97);}
      j++;
      if(j==lenk)j=0;}
    printf("%s\n",a);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
