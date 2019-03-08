#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
      int t[10001][101],    //是否有楼梯
          n,m,s;
      long long num[10001][101],   //显示数字
                x=0;
                
void func(int step,int room)
 {
              int i,j;
              
              if (step==n+1)
                 cout<<x%20123<<endl;
               else{
                    if (t[step][room]==1){
                       x=x+num[step][room];
                       func(step+1,room);
                    }
                     else{
                          x=x+num[step][room];
                          i=0;
                          j=room+1;
                          while(i<num[step][room]){
                             if (t[step][j]==1){                                               
                                i++;
                             }
                             j++;
                             if (j>m-1)
                                j=0;
                          }
                          if (j==0)
                             j=m-1;
                           else
                            j--;
                          func(step+1,j);
                     }
               }
 }
                        
int main()
 {
          freopen("treasure.in","r",stdin);
          freopen("treasure.out","w",stdout);
          
          int i,j;
          
          cin>>n>>m;
          for (i=1;i<=n;i++)
              for (j=0;j<=m-1;j++){
                  cin>>t[i][j];
                  cin>>num[i][j];
              }
          cin>>s;
          
          func(1,s);
          
          fclose(stdin);
          fclose(stdout);
          //system("pause");
          return 0;
 }
