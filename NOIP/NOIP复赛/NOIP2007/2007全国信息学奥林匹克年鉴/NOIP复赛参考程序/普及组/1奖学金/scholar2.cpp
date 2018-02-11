#include <iostream.h>
#include "ctype.h"
#include <iomanip.h>
#include <fstream.h>
char fname1[30],fname2[30];
int n,record[350][5]; //[0]：学号  [1]：语文   [2]：数学  [3]：英语 [4]：总分

void readdata_scholar() //输入原始数据 
{int i;
 cout <<"enter filename for input data:"<<endl;
 cin >>fname1;   
 ifstream myinf(fname1,ios::nocreate);
 if(myinf.fail())
    {cerr<<"error opening file myname\n";
     return;
    }
 myinf >>n;
 for(i=1;i<=n;i++)
 myinf >>record[i][1]>>record[i][2]>>record[i][3];
 myinf.close();
}

void sort1(void)
{int i,j,k,tmp1,tmp2;
 for(i=1;i<n;i++)
   {tmp1=i; 
    for(j=i+1;j<=n;j++)
      if(record[tmp1][4]<record[j][4])
          tmp1=j;
      else if ((record[tmp1][4]==record[j][4])&&(record[tmp1][1]<record[j][1]))
          tmp1=j; 
      else if ((record[tmp1][4]==record[j][4])&&(record[tmp1][1]==record[j][1])
                   &&(record[tmp1][0]>record[j][0]))
         tmp1=j;
   for(k=0;k<=4;k++)
     {tmp2=record[i][k]; record[i][k]=record[tmp1][k]; record[tmp1][k]=tmp2;
     }
   }
 }
void calcul()
{ int i,j;
  for(i=1;i<=n;i++)
    {record[i][0]=i;
     record[i][4]=0;
     for(j=1;j<=3;j++)
       record[i][4]+=record[i][j];
    }
  sort1();
 }
void out_scholar() 
{int i;
 cout <<"enter filename for output data:"<<endl;
 cin >>fname1;   
 ofstream myoutf1(fname1);
 if(myoutf1.fail())
     {cerr<<"error opening file myname\n";
      return;
     }
 for(i=1;i<=5;i++)
  myoutf1 <<record[i][0]<<" "<<record[i][4]<<endl;
 myoutf1.close();
  }
void main()
 { readdata_scholar();   
   calcul();
   out_scholar();
 }

