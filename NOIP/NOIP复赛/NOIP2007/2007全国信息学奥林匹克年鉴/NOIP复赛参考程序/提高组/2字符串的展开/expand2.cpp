#include <iostream.h>
#include "ctype.h"
#include <iomanip.h>
#include <fstream.h>
char fname1[30],fname2[30];
char s1[400],s2[6500];
int p1,p2,p3=1,z1,z2;

void readdata_expand() //输入原始数据 
{cout <<"enter filename for input data:"<<endl;
 cin >>fname1;   
 ifstream myinf(fname1,ios::nocreate);
 if(myinf.fail())
    {cerr<<"error opening file myname\n";
     return;
    }
 myinf >>p1>>p2>>p3;
 myinf >>s1;
 myinf.close();
 cout<<"p:"<<p1<<"  "<<p2<<"  "<<p3<<endl;
 cout<<s1<<endl;
}
void inverse()
{int i,j;
 char t;
 for(i=z1,j=z2;i<j;i++,j--)
 {t=s2[i]; s2[i]=s2[j]; s2[j]=t;
 }
}
void expand()
{ int i,j,k,a,b,c;
  j=0;
  for(i=0;(c=s1[i])!='\0';i++)
    if(c=='-')
      {a=s1[i-1]; b=s1[i+1];
       if ((isalpha(a)&&isalpha(b) || isdigit(a)&&isdigit(b) )&&(tolower(a)<tolower(b)))
       //函数isalpha(a)用于判断字符a是否为字母，isdigit(b) 用于判断字符b是否为数
       //字，如果是，返回1，否则返回0 
	      {if(p1==1)
               {a=tolower(a);b=tolower(b);}
            else if(p1==2)
				{a=toupper(a);b=toupper(b);}
            z1=j;     
	        while(tolower(a)<tolower(b)-1)
				{a++;
			     for(k=1;k<=p2;k++)
                 {if(p1==3)
                    s2[j]='*';
                  else
                    s2[j]=a;
                  j++;
                 }
				}
			z2=j-1;
			if(p3==2) 
              inverse();
           }
           else s2[j++]=c;
		}
     else s2[j++]=c;
  s2[j]='\0';
 }
void out_expand() 
{cout <<"enter filename for output data:"<<endl;
 cin >>fname1;   
 ofstream myoutf1(fname1);
 if(myoutf1.fail())
     {cerr<<"error opening file myname\n";
      return;
     }
 myoutf1 <<s2<<endl;
 myoutf1.close();
  }
void main()
 { readdata_expand();   
   expand();
   out_expand();
   cout<<s2<<endl;
 }

