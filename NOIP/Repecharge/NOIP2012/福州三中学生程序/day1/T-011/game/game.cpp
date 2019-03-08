#include<iostream>
#include<stdin.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm.h>
using namespace std;
int main()
{
    int n,a[1000],b[1000];
    long long t[1000],m=0;
    int i,k; 
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a[0]>>b[0];
    for(i=1;i<=n;i++)
    {cin>>a[i]>>b[i];
     t[i]=a[0];}
    for(i=1;i<=n;i++)
       {  
           for(k=1;k<=i;k++)
           t[i]=a[k]*t[i];
           t[i]=t[i]/b[i];
           if(m<t[i])
           m=t[i];
           cout<<m<<endl;
       }    
    cout<<m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
