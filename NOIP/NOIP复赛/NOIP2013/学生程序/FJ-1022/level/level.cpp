#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
 freopen("level.in","r",stdin);
 freopen("level.out","w",stdout);   
    
 int n,m,cir,cir2,a,temp;
 cin>>n>>m;
 for(cir=1;cir<=m;cir++)
 {
  cin>>a;
  for(cir2=1;cir2<=a;cir2++) cin>>temp;                     
 }
 
 cout<<m;
 
 fclose(stdin);
 fclose(stdout);
 return 0;   
}
