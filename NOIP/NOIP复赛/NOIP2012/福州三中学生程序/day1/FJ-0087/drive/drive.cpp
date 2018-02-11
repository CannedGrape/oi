#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;
int maxx=0xfffffff;
int n,m,x0,x,y;
int hi[100010];
int disa[100010][3];
int disb[100010][3];

inline int abs(int a){if(a<0) return a*-1;else return a;}

void init()
{
     int i,j,k;
     
     scanf("%d",&n);
     for(i=1;i<=n;i++)
       scanf("%d",&hi[i]);
     scanf("%d",&x0);
     
     for(i=1;i<n;i++){
     disa[i][1]=-1,disa[i][2]=maxx;
     disa[i][1]=-1,disb[i][2]=maxx;
     
     for(j=i+1;j<=n;j++){
     k=abs(hi[i]-hi[j]);//cout<<k<<" ";
     if(k<disa[i][2] || ( (k==disa[i][2])&& (hi[disa[i][1]]>hi[j]) )  )
       disa[i][2]=k,disa[i][1]=j;} 
     for(j=i+1;j<=n;j++)
     if(j!=disa[i][1]){
     k=abs(hi[i]-hi[j]);
     if(k<disb[i][2] || ( (k==disb[i][2])&& (hi[disb[i][1]]>hi[j]) )  )
       disb[i][2]=k,disb[i][1]=j;} }
     
     disa[n][1]=-1,disb[n][1]=-1,disb[n-1][1]=-1,disb[n-1][2]=0;
}

void count(int city,int maxd)
{
     bool con=true;
     bool gg=0;
     int f=city;
     x=0,y=0;
     while(con){
     if(gg){
     if(f>n-1 || x+y+disa[f][2]>maxd) {con=false;break;}
     y+=disa[f][2];
     f=disa[f][1];}
     else{
     if(f>n-2 || x+y+disb[f][2]>maxd) {con=false;break;}
     x+=disb[f][2];
     f=disb[f][1]; }
     gg=!gg;
     }
}

void work()
{
     int i,k1,k2,lc=0;
     double dd=maxx*1.0;
    
     for(i=1;i<=n;i++){
     count(i,x0);
     if(y==0 && dd==maxx*1.0) 
     {if(lc==0) lc=i;
      else if(hi[i]>hi[lc]) lc=i;}
     else
     {if( x*1.0 < dd*y*1.0 ) lc=i,dd=x/y;
      else if( x*1.0 == dd*y*1.0 && hi[i]>hi[lc]) lc=i;} 
     }
     
     printf("%d\n",lc);
     
     scanf("%d",&m);
     for(i=1;i<=m;i++){
     scanf("%d%d",&k1,&k2);
     count(k1,k2);
     printf("%d %d\n",x,y);
     }
}

int main()
{
    freopen("drive.in","r",stdin);
    freopen("drive.out","w",stdout);
    
    init();
    work();
    
    fclose(stdin);
    fclose(stdout);
   // system("pause");
    return 0;
}
