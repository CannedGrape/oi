#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

long long q[1000001],m,n,j,k,d,s,t;
bool pd;

void clas(void)
{
     for(int i=1;i<=m;i++)
       {cin>>d>>s>>t;
        k=i;
        for(int j=s;j<=t;j++)
          {if(q[j]<d)
             {pd=1;return;}
           else
             q[j]=q[j]-d;
          }
        if(pd==1)
          return ;
       }
}

int main()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>q[i];
    
    /*clas();*/
    
    while(k<m && pd==0)//×¢Òâ·ûºÅ 
      {k++;
       cin>>d>>s>>t;
       j=s;
       while(j<=t && pd==0)
         {if(q[j]<d)
            pd=1;
          else
            q[j]=q[j]-d;
          j++; 
         }
      }
    if(pd==0)
      cout<<0;
    else
      cout<<-1<<endl<<k;
    fclose(stdin);
    fclose(stdout);
    return 0;
    
    
}
