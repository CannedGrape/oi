#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
const int mod=1000007;
int n,m,a[1001],sum[1001],fsum,esum,now;
long long ans;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d%d",&n,&m);
    int i,j,k;
    ans=1;
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    for(i=1;i<=m;i++){
      for(j=1;j<=n;j++){
        for(k=j-1;k>=1;k--)
          esum+=a[k];
        for(k=j+1;k<=n;k++)
          fsum+=a[k];
        if(a[j]+i-1>=m&&i-a[j]+1<=1)
          sum[i]++;
        else
          if(((fsum>0&&a[j]+i+fsum-2>=m)||(fsum==0&&a[j]+i-1>=m))&&((esum>0&&i-a[j]-esum+2<=1)||(esum==0&&i-a[j]+1<=1)))
            sum[i]++;
        fsum=0;
        esum=0;
        }
      if(sum[i]!=0){
        ans*=sum[i];
        ans%=mod;
        }
      }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
