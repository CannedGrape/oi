#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int n,h[100001],xz,m,ab[10001][4],bz[10001],minbz,ax[2],bx;
void lc(int i)
{   int t=ab[i][0],j;
    while(t<=n-2)
      {ax[1]=n;
       for(j=t+1;j<=n-1;j++)
         {if(abs(h[j]-h[t])>abs(h[t]-h[ax[1]]))ax[1]=j;
          else if(abs(h[j]-h[t])==abs(h[t]-h[ax[1]]))
                {if(h[ax[1]]>h[j])ax[1]=j; break;}
         }
       for(j=t+1;j<=n;j++)
         {if(j==ax[1]||j==ax[0])continue;
          if(abs(h[j]-h[t])<abs(h[t]-h[ax[1]])){ax[0]=ax[1];ax[1]=j;}
          else if(abs(h[j]-h[t])==abs(h[t]-h[ax[1]]))
                {if(h[ax[1]]>h[j]){ax[0]=ax[1];ax[1]=j;}}
         }
       if(ab[i][2]+ab[i][3]+abs(h[t]-h[ax[0]])>ab[i][1])break;
       else {ab[i][2]+=abs(h[t]-h[ax[0]]);t=ax[0];}
       if(t>n-2)break;
       bx=n;
       for(j=t+1;j<=n-1;j++)
         {if(abs(h[j]-h[t])<abs(h[t]-h[bx]))bx=j;
          else if(abs(h[j]-h[t])==abs(h[t]-h[bx]))
                {if(h[bx]>h[j])bx=j; break;}
         }
       if(ab[i][2]+ab[i][3]+abs(h[t]-h[bx])>ab[i][1])break;
       else {ab[i][3]+=abs(h[t]-h[bx]);t=bx;}
      }
}
int main()//
{   freopen("drive.in","r",stdin);freopen("drive.out","w",stdout);
    scanf("%d",&n);  int i;
    for(i=1;i<=n;i++)scanf("%d",&h[i]);
    scanf("%d %d",&xz,&m);
    for(i=1;i<=m;i++)scanf("%d %d",&ab[i][0],&ab[i][1]);
    for(i=1;i<=m;i++)
      {if(ab[i][0]>n-2)
       {ab[i][2]=0;ab[i][3]=0;bz[i]=1;continue;}
       else {lc(i);
             if(ab[i][3]==0)bz[i]=-1;
             else if(ab[i][2]==ab[i][3]) bz[i]=1;
                  else bz[i]=ab[i][2]/ab[i][3];
            }
      }minbz=1;
    for(i=2;i<=m;i++)if((bz[i]<bz[minbz])&&(bz[i]!=-1))minbz=i;
    printf("%d\n",minbz);
    for(i=1;i<=m;i++)
      printf("%d %d\n",ab[i][2],ab[i][3]);
    fclose(stdin);fclose(stdout);
    return 0;
}
