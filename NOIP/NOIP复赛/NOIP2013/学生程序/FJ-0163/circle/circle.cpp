#include <iostream>
#include <stdio.h>
using namespace std;
long long n,m,k,x,ans,ans1,ans2;
long long  a[101],b[101];
int main(){
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    a[0]=1;
    for(int i=1;i<=40;i++)
       a[i]=a[i-1]*2;
    b[0]=10%n;
    for(int i=1;i<=40;i++)
       b[i]=((b[i-1]%n)*(b[i-1]%n))%n;
    ans1=0;ans2=1;
    while(k!=0){
       if(k%2==1){
          ans2=(ans2*b[ans1])%n;
       }
       ans1++;
       k=k/2;
    }
    ans2=((m%n)*ans2)%n;
    ans2=(ans2+x)%n;
    cout<<ans2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
