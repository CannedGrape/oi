#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
bool flag[0][100001]={};
long long myin=0;
int myput[100001]={};
int i,j,k,myn=0;
char myaa;
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    myaa='+';
    while(myaa=='+'||myaa=='*')
      {cin>>myin;
       myn++;
       myin%=10000;
       myput[myn]=myin;
       myaa=getchar();
       if(myaa=='*') flag[1][myn]=1;
       flag[0][myn]=1;
      }
    for(i=1;i<=myn-1;i++)
      {if((flag[1][i]==1)&&(flag[0][i]==1))
         {j=i+1;
          while(flag[0][j]==0)
            j++;
          myput[i]=myput[j]*myput[i]%10000;
          flag[0][j]=0;
          flag[1][i]=flag[1][j];
          i--;
         }
      }
    
    for(i=2;i<=myn;i++)
      if(flag[0][i]==1)
        {myput[1]+=myput[i];
         myput[1]%=10000;
        }
    cout<<myput[1]<<endl;
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
