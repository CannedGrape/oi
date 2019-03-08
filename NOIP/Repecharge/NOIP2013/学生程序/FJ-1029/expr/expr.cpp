#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
#include<math.h>
using namespace std;
string st;
long long len,num[100001],a[100001],ans;
int ans1[4];
void make_num(int x,int y)
{
     int i,t=1;
     for(i=x-1;i>=0;i--)
       if(st[i]!='+'&&st[i]!='*'){
         num[y]+=t*(st[i]-48);
         t*=10;
         }
       else
         break;
           
}
void doing()
{
     int i,j,x=1;
     for(i=1;i<=50000;i++){
       num[i]=0;
       a[i]=0;
     }
     for(i=0;i<len;i++){
       if(st[i]=='+'){
         a[x]=1;
         make_num(i,x);
         x++;
         }
       if(st[i]=='*'){
         a[x]=2;
         make_num(i,x);
         x++;
       }
     }
     int t=1;
     for(i=len-1;i>=0;i--)
       if(st[i]!='+'&&st[i]!='*'){
         num[x]+=t*(st[i]-48);
         t*=10;
         }
       else
         break;
     for(i=1;i<x;i++)
       if(a[i]==2){
         num[i]*=num[i+1];
         for(j=i;j<x;j++)
           a[j]=a[j+1];
         for(j=i+1;j<=x;j++)
           num[j]=num[j+1];
         i=0;
         }
      for(i=1;i<x;i++)
       if(a[i]==1){
         num[i]+=num[i+1];
         for(j=i;j<x;j++)
           a[j]=a[j+1];
         for(j=i+1;j<=x;j++)
           num[j]=num[j+1];
         i=0;
         }
     for(i=1;i<=x;i++)
       ans=max(num[i],ans);
     for(i=1;i<=4;i++){
       ans1[4-i]=ans%10;
       ans/=10;
       }
     bool b=0;
     for(i=0;i<4;i++){
       if(ans1[i]!=0&&!b){
         printf("%d",ans1[i]);
         b=1;
         }
       else
         if(b)
           printf("%d",ans1[i]);
     }
     if(!ans1[0]&&!ans1[1]&&!ans1[2]&&!ans1[3])
       printf("0");
}
void init()
{
     cin>>st;
     len=st.size();
     doing();
}
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    init();
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
