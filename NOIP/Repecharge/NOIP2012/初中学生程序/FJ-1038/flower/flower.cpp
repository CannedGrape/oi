#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
      int n,m,
          a[101],   //每种花能摆的最多盆数
          b[101],   //m盆花
          c[101],    
          minn=0;    //种数 
void func(int i)
 {
              int j;
              
              for (j=1;j<=n;j++)
                  if (c[j]>0 && b[i-1]<=j){
                     b[i]=j;
                     c[j]--;
                     if (i==m)
                        minn++;
                      else 
                           func(i+1);
                     c[j]++;
                  }      
 }
                     
int main()
 {
          freopen("flower.in","r",stdin);
          freopen("flower.out","w",stdout);
          
          int i;
          
          memset(b,0,sizeof(b));
          memset(c,0,sizeof(c));
          cin>>n>>m;
          for (i=1;i<=n;i++){
              cin>>a[i];
              c[i]=a[i];
          }
          
          func(1);
          cout<<minn%1000007<<endl;
          
          fclose(stdin);
          fclose(stdout);
          //system("pause");
          return 0;
 }
          
