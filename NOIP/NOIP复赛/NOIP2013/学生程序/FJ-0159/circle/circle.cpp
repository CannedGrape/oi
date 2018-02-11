#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
  freopen ("circle.in","r",stdin);
  freopen ("circle.out","w",stdout);
  int m,n,x,l=1;
  long long k,i;
  cin>>n>>m>>k>>x;
  //scanf("%d %d %64d %d",&n,&m,&k,&x);
  for(i=1;i<=k;i++)
    l=l*10;
  l=l%n;
  if(l==0)
    cout<<x;
  if(l!=0)
   {x=(x+l*m)%n;
   cout<<x;}
  fclose(stdin);
  fclose(stdout);
  //system("pause");
  return 0;
}
