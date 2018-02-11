#include<cstdio>
#include<iostream>
using namespace std;
int a[1000001],b[1000001],c[1000001];
int Max(int X,int Y){return X>Y?X:Y;}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,p;
    cin>>n>>p;
    for(int i=1;i<=n;++i)
    scanf("%d",&a[i]);
    c[1]=b[1]=a[1];
    int sum=a[1];
    int Maxsum=-2147483647;
    for(int i=2;i<=n;++i)
    {
        sum=(sum+a[i])>0?sum+a[i]:sum;
        Maxsum=Max(Maxsum,sum);
        b[i]=Maxsum;
    }
    int Maxvalue=c[1]+b[1];
    for(int i=2;i<=n;++i)
    c[i]=Max(Maxvalue,c[i-1]+b[i-1]);
    int Maxans=-2147483647;
    for(int i=1;i<=n;++i)
    Maxans=Max(Maxans,c[i]);
    cout<<Maxans%p;
    fclose(stdin);fclose(stdout);
}
    
