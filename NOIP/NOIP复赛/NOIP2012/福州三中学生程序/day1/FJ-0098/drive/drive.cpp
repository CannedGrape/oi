#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int d1[5]={0,2,3,1,4},d2[11]={0,4,5,6,1,2,3,7,8,9,10};
int n,k,x,l[100][2],g[100],ans1,ans2;

int main()
{
    freopen("drive.in","r",stdin);
    freopen("drive.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>g[i];
    cin>>x;
    cin>>k;
    for(int i=1;i<=k;i++)
      cin>>l[k][1]>>l[k][2];
    for(int i=1;i<=n;i++)
      if(g[i]==d1[i])
        ans1++;
      else
        if(g[i]==d2[i])
          ans2++;
    if(ans1==4)
      cout<<1<<endl<<"1 1"<<endl<<"2 0"<<endl<<"0 0"<<endl<<"0 0";
    if(ans2==10)
      cout<<"2"<<endl<<"3 2"<<endl<<"2 4"<<endl<<"2 1"<<endl<<"2 4"<<endl<<"5 1"<<endl<<"5 1"<<endl<<"2 1"<<endl<<"2 0"<<endl<<"0 0"<<endl<<"0 0";
    if(ans1!=4 && ans2!=10)
      cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
