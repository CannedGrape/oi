#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;
int n,m,k,x,ans,sum;
bool p,w,ok;
int pow(int y,int z)
{
  if (y==1) 
   return(10%z);
  else 
   if (y%2==1) return((pow(y/2,z)*pow(y/2,z)*10)%z);
   else return((pow(y/2,z)*pow(y/2,z))%z);      	
}
int main(){
  freopen("circle.in","r",stdin);
  freopen("circle.out","w",stdout);
   scanf("%d%d%d%d",&n,&m,&k,&x);
   ans=pow(k,n);
   printf("%d",(ans*m+x)%n);
  fclose(stdin); fclose(stdout);
}

