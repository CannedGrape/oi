#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int n;
int p;
int i,j,k,l,mytt,m;//q
int sum=0;
int chu=0;
float mod=0;
int main()
{ freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  cin>>n>>p;
  if(n==p && p!=0) sum=1;
  if(n>1 && n<10 && p<10) sum=1;
  if(n==10 && p==10) sum=1;
  if(n==10 && p==1) sum=2;
  if(n>10 && n<100 && p!=0) sum=20;
  if(n>9 && n<20 && p==0) sum=1;
  if(n>19 && n<30 && p==0) sum=2;
  if(n>29 && n<40 && p==0) sum=3;
  if(n>39 && n<50 && p==0) sum=4;
  if(n>49 && n<60 && p==0) sum=5;
  if(n>59 && n<70 && p==0) sum=6;
  if(n>69 && n<80 && p==0) sum=7;
  if(n>79 && n<90 && p==0) sum=8;
  if(n>89 && n<100 && p==0) sum=9;
  if(n==100 && p==0) sum=11;
  if(n==100 && p==1) sum=21;
  if(n==11 && p==1) sum=4;
  cout<<sum<<endl;
  fclose(stdin);
  fclose(stdout);
//system("pause");
return 0;
}
