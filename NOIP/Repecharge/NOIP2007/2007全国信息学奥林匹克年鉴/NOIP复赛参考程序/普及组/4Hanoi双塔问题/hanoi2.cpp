#include <iostream.h>
#include "ctype.h"
#include <iomanip.h>
#include <fstream.h>
#define N 100
int a[N]={0};
char fname1[30],fname2[30];
long n,count;

void form1(int c[],int n)//格式化
{int i;
 for (i=1;i<N-10;i++)
   if(c[i]>9)
     {c[i+1]+=c[i]/10;
      c[i]%=10;
     }
 }

void mult2(int a[],int n)// a[n]*2=>a[n] 
{int j;
 for(j=1;j<N-10;j++)  a[j]=a[j]*2;
 form1(a,n);
}

void readdata_hanoi1() //输入原始数据 
{cout <<"enter filename for input data:"<<endl;
 cin >>fname1;   
 ifstream myinf(fname1,ios::nocreate);
 if(myinf.fail())
    {cerr<<"error opening file myname\n";
     return;
    }
 myinf >>n;
 myinf.close();
}

void  calcul()
{int i,k;
 count=1;
 if(n<26) 
  {for(i=1;i<=n+1;i++)
    count=count*2;
   count=count-2;
   return;  
  }
 a[1]=1;
 for(i=2;i<N;i++) a[i]=0;
 for(i=1;i<=n+1;i++)
   mult2(a,n);
 a[1]-=2;
 k=1; 
 while(a[k]<0)
  {a[k]+=10; a[k+1]--; k++;
  }
 }


void out_hanoi1() 
{int j,k;
	cout <<"enter filename for output data:"<<endl;
 cin >>fname1;   
 ofstream myoutf1(fname1);
 if(myoutf1.fail())
     {cerr<<"error opening file myname\n";
      return;
     }
if(n<26) 
  {myoutf1 <<count<<endl;
   myoutf1.close();
   return;
  }
 j=N-1; 
 while(a[j]==0) j--;
 for(k=j;k>=1;k--)
   myoutf1 <<a[k];
 myoutf1<<endl;
 myoutf1.close();
 
}
void main()
 { readdata_hanoi1();   
   calcul();
   out_hanoi1();
   cout<<count<<endl;
 }
