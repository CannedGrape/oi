#include<cstdio>
#include<cstring>
int a[1000001]={0},b[1000001],c[1000001]={0},max=-0x7fffffff,su,i,j,n,q;
int bigp(int x,int n){
    int ma=-0x7fffffff;
    for (int i=x; i<=n; i++){
        int sum=a[i];
        for (int j=i+1; j<=n; j++)
        {
            if (sum+a[j]<sum) break;
            else sum+=a[j];
        }
        if (ma<sum) ma=sum;
    }
    return ma;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(b,-0x7ffffff,sizeof(b));
    scanf("%d%d",&n,&q);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);
    for (i=1; i<=n; i++)
      b[i]=bigp(1,i);
      c[1]=max=b[1];
    for (i=2; i<=n; i++){
        int ma=-0x7fffffff;
        for (j=1; j<i; j++) if (b[j]+c[j]>ma) ma=b[j]+c[j];
        c[i]=ma;
        if (ma>max) max=ma;
    }
    printf("%d",max%q);   
    fclose(stdin);
    fclose(stdout);
    return 0;
}
           
