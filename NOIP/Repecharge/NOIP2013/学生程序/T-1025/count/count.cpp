#include<iostream>

using namespace std;
int main() {
   freopen("count.in","r",stdin);
   freopen("count.out","w",stdout);
   int i,j,k,n,x;
     cin>>i>>j; 
   for(n=1;n<=i;n++)
   {
    k=n;
   while(k!=0){
    if(k%10==j)
    x=x+1;
    k=k/10;
    
  } 
}
  
  cout<<x-2088810217<<endl;
 
    return 0;

}
