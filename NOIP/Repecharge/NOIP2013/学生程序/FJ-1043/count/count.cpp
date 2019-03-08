#include<cstdio>
int n,i,f,sum;
void ss(int a){
    int x=a%10;
    a/=10;
    if (x==f) sum++;
    if (a>0) ss(a);
}
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d%d",&n,&f);
    for (i=1; i<=n; i++)ss(i);
    printf("%d\n",sum);
    fclose(stdin);fclose(stdout);
    return 0;
}
