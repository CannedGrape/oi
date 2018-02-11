#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
char sources[1111]={},str1[11]={},str2[11]={},str3[11]={},ans[12]={};
int sourcelen;
void jia()
{
     int len1=strlen(str1);
     int len2=strlen(str2);
     int dw=0;
     int i;
     for(i=len1;i>=0;i--)
     {
         ans[dw]+=str1[i]+str2[len2-dw]; 
         ans[dw+1]+=ans[dw]/10;
         ans[dw]-=10*ans[dw+1]; 
         dw++;                  
     }
}
void cheng(bool kind)
{
     int len1=strlen(str1);
     int len2=strlen(str2);
     int len3=strlen(str3);
     int dw=0;
     int i;
     if(kind==0)
     for(i=len1;i>=0;i--)
     {
         ans[dw]+=str1[i]*str2[len2-dw];
         ans[dw+1]+=ans[dw]/10;
         ans[dw]-=10*ans[dw+1];
         dw++;
     }
     if(kind==1)
     for(i=len2;i>=0;i--)
     {
         ans[dw]+=str2[i]*str3[len3-dw];
         ans[dw+1]+=ans[dw]/10;
         ans[dw]-=10*ans[dw]+1;
     }  
}
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    cin.getline(sources,1111111);
    sourcelen=strlen(sources);
    int i,o=0;
    int j,k;
    int l,n;
    int m,b;
    //int right=0,left=0;
    for(i=0;i<=sourcelen;i++)
    {
        k=0;
        b=0;
        if(sources[i]=='+')
        {
           o=0;
           for(j=i+1;j<=sourcelen-1;j++)
           {
                if(sources[j]=='+')
                {
                     jia();
                     k=0;
                     break;
                }
                else{
                     if(sources[j]=='*')
                     {
                        for(l=j+1;l<=sourcelen-1;l++)
                        {
                             if((sources[l]=='+')||(sources[l]=='*'))
                             {
                                   cheng(1);
                                   n=0;
                                   break;
                             }
                             else 
                             {
                                  str3[n]=sources[l];
                                  n++;
                             }
                        }  
                     }
                     else 
                     {
                        str2[k]==sources[j];
                        k++;
                     }
                }
            }
        }
        else 
        {
             if(sources[i]=='*')
                 for(m=i+1;m<=sourcelen;m++)
                 {
                     if((sources[m]=='*')||(sources[m]=='+'))
                     {
                          cheng(0);
                          b=0;
                          break;
                     }
                     else
                     {
                         str2[b]=sources[m];
                         b++;
                     }
                 }
             else
             {
                 str1[o]=sources[i];
                 o++;
             }
        }
    }
    int z;
    for(z=3;z>=0;z--)
       cout<<ans[i];
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
