#include<cstdio>
const long oo=1000000007;
int i,j,n,m,mo;
long t[1001],s[1001],te[1001],f[1001];
int main() {
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
scanf("%d%d",&n,&mo);
for(i=1;i<=n;i++) {scanf("%d",&s[i]); t[i]=s[i]>0; }
long max=-oo;
for(i=1;i<=n;i++) for(j=1;j<=i;j++) {te[i]+=(t[i]*s[i])%mo; if((te[i]+s[i])%mo>max) max=te[i]+s[i];}
f[1]=te[1];
if(f[1]>max) max=f[1];
printf("%d",max);
return 0;
}