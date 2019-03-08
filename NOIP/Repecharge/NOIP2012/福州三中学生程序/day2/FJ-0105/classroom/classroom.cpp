#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    long long k,i,j,n,m,a[10000][2]={},b[10000]={};
    long long sa=0;    
    cin>>n>>m;
    for(i=1;i<=n;i++)
      cin>>b[i];
    for(i=1;i<=m;i++)
      for(j=0;j<=2;j++)
        cin>>a[i][j];
    for(i=1;i<=m;i++)    
      for(j=a[i][1];j<=a[i][2];j++)
        {b[j]=b[j]-a[i][0];
        //cout<<b[i];
         /*for(k=1;k<=n;k++)
           cout<<b[k]<<" ";*/
         if(b[j]<0)
           {cout<<-1<<endl<<i;
           return 0;}
         }
    for(i=1;i<=n;i++)
      if(b[n]>=0)
        sa=sa+1;
      if(sa==n)
        cout<<0;
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
      
