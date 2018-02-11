#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long anss=0;
int n,k,x;
int main()
{
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  cin>>n>>x;
  for(int i=1;i<=n;i++)
    {
    k=i;
    while(k>0)
      {
      if(k%10==x)
        anss++;
      k=k/10;
      }
    }
  cout<<anss<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
