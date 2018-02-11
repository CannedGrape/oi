#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int n;
int a[100001],b[100001],c[100001],d[100001];
int e[100001],f[100001];
int LRA[100001][2],LRB[100001][2];
int leftA[100001],leftB[100001],rightA[100001],rightB[100001];
int Ls[100001],Rs[100001],Rrs[100001],Lrs[100001];
bool LorR[100001];
int tot;
void qsorta(int l,int r)
{
    int i,j,mid;
    i=l;j=r;mid=c[(l+r)/2];    
    while(i<j)
    {
        while(c[i]<mid)i++;
        while(c[j]>mid)j--;
        if(i<=j)
        {swap(c[i],c[j]);swap(e[i],e[j]);i++;j--;}
    }
    if(l<j)qsorta(l,j);
    if(i<r)qsorta(i,r);          
}
void qsortb(int l,int r)
{
    int i,j,mid;
    i=l;j=r;mid=d[(l+r)/2];    
    while(i<j)
    {
        while(d[i]<mid)i++;
        while(d[j]>mid)j--;
        if(i<=j)
        {swap(d[i],d[j]);swap(f[i],f[j]);i++;j--;}
    }
    if(l<j)qsortb(l,j);
    if(i<r)qsortb(i,r);          
}
void qsortleft(int l,int r)
{
    int i,j,mid;
    i=l;j=r;mid=leftB[(l+r)/2];    
    while(i<j)
    {
        while(leftB[i]<mid)i++;
        while(leftB[j]>mid)j--;
        if(i<=j)
        {swap(leftA[i],leftA[j]);swap(leftB[i],leftB[j]);swap(Ls[i],Ls[j]);i++;j--;}
    }
    if(l<j)qsortleft(l,j);
    if(i<r)qsortleft(i,r);          
}
void qsortright(int l,int r)
{
    int i,j,mid;
    i=l;j=r;mid=rightB[(l+r)/2];    
    while(i<j)
    {
        while(rightB[i]<mid)i++;
        while(rightB[j]>mid)j--;
        if(i<=j)
        {swap(rightA[i],rightA[j]);swap(rightB[i],rightB[j]);swap(Rs[i],Rs[j]);i++;j--;}
    }
    if(l<j)qsortright(l,j);
    if(i<r)qsortright(i,r);           
}
void init()
{
     int am=0,bm=0; 
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
     for(int i=1;i<=n;i++)
       scanf("%d",&b[i]);    
     for(int i=1;i<=n;i++)
     {c[i]=a[i];e[i]=i;}
     for(int i=1;i<=n;i++)
     {d[i]=b[i];f[i]=i;}
     qsorta(1,n);
     qsortb(1,n);         
     for(int i=1;i<=n;i++)
     {
          if(e[i]-f[i]>0)  
            {LorR[i]=1;am++;LRA[am][1]=f[i];LRB[am][1]=e[i];rightA[am]=f[i];rightB[am]=e[i];Rs[am]=am;Rrs[i]=am;}
          if(e[i]-f[i]<0)
            {bm++;LRA[bm][0]=f[i];LRB[bm][0]=e[i];leftA[bm]=f[i];leftB[bm]=e[i];Ls[bm]=bm;Lrs[i]=bm;}                 
     }     
     qsortleft(1,am);
     qsortright(1,bm);        
     while(am>0||bm>0)
     {            
         if(am>0)             
         {
             for(int i=LRA[Rs[am]][1];i<=LRB[Rs[am]][1]-1;i++)
              {
                tot++;
                if(LorR[i+1]==1)
                  LRA[Rrs[i+1]][1]-=1;
                else 
                  LRA[Lrs[i+1]][0]-=1;
              }
             am--;
         }      
         //printf("-------\n");
         if(bm>0)             
         {
             for(int i=LRA[Ls[bm]][0];i>=LRB[Ls[bm]][0]+1;i--)
             {
                 tot++;
                 if(LorR[i+1]==1)
                   LRA[Rrs[i-1]][1]+=1;
                 else
                   LRA[Lrs[i-1]][0]+=1;                 
                 
             }bm--;
         }          
     }
     printf("%d\n",tot);
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    init();   
    return 0;
}
