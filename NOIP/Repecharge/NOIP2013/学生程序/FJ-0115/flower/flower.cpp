#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m=0,h[100001]={};
bool bo=true;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i,nu=0,nm=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      {
       scanf("%d",&h[i]);
       if ((h[i]!=h[i-1])&&(i>1))
         bo=false;
       }
    if (bo==true) m=1;
    for (i=2;i<=n-1;i++)
      if ((h[i]>h[i+1])&&(h[i]>h[i-1]))
        nu++;
    for (i=2;i<=n-1;i++)
      if ((h[i]<h[i+1])&&(h[i]<h[i-1]))
        nm++;
    if (m==1)
      cout<<m<<endl;
    else
      {
        if (nu>=nm)
          cout<<nu+2<<endl;
        else
          cout<<nm+2<<endl;
      }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
