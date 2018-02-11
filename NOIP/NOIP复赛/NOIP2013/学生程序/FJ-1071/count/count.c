#include<stdio.h>
int a[1000001]={0};
int s[100000001]={0};
int n,x;
long total=0;
long pow10(int a)
{
     int ans=10,i;
     for(i=1;i<a;i++) ans*=10;
     return ans;
}
     
void getnum(int i)
{
     int j;
     for(j=1;j<=i;j++) a[j]=j;
}
void num(int i)
{
     int j=0,d=1,num,y=1,z;
     while(y-1!=i)
     {
           z=y;
           if(y%(pow10(d))==0) d++;    
           for(num=1;num<=d;num++)
           {
                 total++;
                 s[total]=z%10;
                 z=z/10;
           }
           y++;
     }
}
long countnum()
{
     int i,ans=0;
     for (i=0;i<=total;i++) if (s[i]==x) ans++;
     return ans;
}
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d %d",&n,&x);
    getnum(n);
    num(n);
    printf("%ld",countnum());
    return 0;
}
