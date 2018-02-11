#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,x,sum=0;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int i,k;
    cin>>n>>x;
    for(i=1;i<=n;i++)
      {k=i;
       while(k>0)
         {if(k%10==x) sum++;
          k=k/10;}
      }
    cout<<sum<<endl;
    //system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
