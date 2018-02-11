#include<iostream>
#include<stdlib.h>
using namespace std;

int slist[1000001],tlist[1000001],flist[1000001];

int findmax(int end)
{
 int max,cir;//youwuzhengshu
 bool a=false;//wuzhengshi false
 max=-147483648;
 for(cir=1;cir<=end;cir++)
 if(a)
 {
      if(slist[cir]>0)
      {
        max+=slist[cir];
        a=true;
      }
 }
 else if(slist[cir]>0)
 {
  a=true;
  max=slist[cir];    
 }
 else if(slist[cir]>max) max=slist[cir];
 
 return max;    
}

int findmax2(int end)
{
 int max,cir;
 max=tlist[1]+flist[1];
 for(cir=2;cir<=end-1;cir++)
 if(tlist[cir]+flist[cir]>max) max=tlist[cir]+flist[cir];
 
 return max;   
}

int main()
{
 freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);   
    
 int n,p,cir,cir2,fmax;
 
 cin>>n>>p;
 for(cir=1;cir<=n;cir++) cin>>slist[cir];
 
 for(cir=1;cir<=n;cir++)
   tlist[cir]=findmax(cir);
 
 flist[1]=tlist[1];  
 for(cir=2;cir<=n;cir++)
   flist[cir]=findmax2(cir);
 
 fmax=flist[1];
 for(cir=2;cir<=n;cir++)
 if(flist[cir]>fmax) fmax=flist[cir];
 
 if(fmax<0)
 {
  cout<<'-';
  fmax*=-1;         
 }
 cout<<fmax%p;
 
 fclose(stdin);
 fclose(stdout);
 return 0;   
}
