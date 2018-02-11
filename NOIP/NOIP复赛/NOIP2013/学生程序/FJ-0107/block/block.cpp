#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int n,h[100000]={},i=0,j=0,k=0,hehe=0,ans=0;

int getrp(int a,int b,int c,int d){
    if(a>b)
      {return 0;
      }
int maxab=0;
int head;
    head=a;
    if(d==-1)
    {for(j=a;j<=b;j++)
      {maxab=max(maxab,h[j]);
      }
    }
    else
    {maxab=d;
    }
    if(c==maxab)
      {ans++;
       return 0;
      }
    for(j=a;j<b;j++)
      {if(h[j]<c&&j>a)
         {ans++;
          getrp(head,j-1,c+1,-1);
          head=j+1;
         }
       else
        {if(h[j]<c&&j==a)
            {head++;
            }
         }
      }

    if(h[j]>c)
      {getrp(head,j,c+1,-1);
       ans++;
      }
    else
      {ans++;
       getrp(head,j-1,c+1,-1);
      }
    return 0;    
}
int main(){
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    cin>>n;
    
    for(i=0;i<n;i++)
      {cin>>h[i];
      }
    getrp(0,n-1,1,-1);
    cout<<ans;
    return 0;
}
