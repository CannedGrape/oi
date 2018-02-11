#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int n,m,i,j,k=1,q,hehe,zgg;
int temp[3]={};
int city[1000][30002][2]={0};
int car[30000][5]={};

int check(int a,int b,int c){
int hgg=97109999,tmp;
    for(j=1;j<=city[car[c][0]][0][0];j++)
      {if(city[car[c][0]][j][1]==a)
         {hgg=min(hgg, city[car[c][0]][j][2]);
          cout<<"!"<<hgg<<"!"<<endl;
         }
      }
    b--;
    if(b==0&&hgg==97109999)
      {return -1;
      }
    else
      {if(b<0)
         {for(j=1;j<=city[car[c][0]][0][0];j++)
           {c=city[car[c][0]][j][1];
            tmp=check(a,b,c);
            if(tmp!=-1)
             {hgg=min(hgg,tmp);
             }
           }
         }
       return hgg;
      }
}
int main(){
int tmp;
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d %d",&n,&m);
    
    for(i=0;i<m;i++)
      {scanf("%d %d %d",&temp[0],&temp[1],&temp[2]);
       city[temp[0]][0][0]++;
       city[temp[0]][city[temp[0]][0][0]][1]=temp[1];
       city[temp[0]][city[temp[0]][0][0]][2]=temp[2];
      }
    scanf("%d",&q);
    for(i=0;i<q;i++)
      {scanf("%d %d",&car[i][0],&car[i][1]);
      }
    for(i=0;i<q;i++)
      {k=1;
       while(1){tmp=check(car[i][1],k,i);
                if(k<=40000&&tmp==-1)
                  {k++;
                  }
                else
                  {if(tmp!=-1)
                    {cout<<tmp<<endl;
                     break;
                    }
                  }
                }
       }
       return 0;
}
                
