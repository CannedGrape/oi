#include<iostream>
#include<cstdio>
using namespace std;
int max(int a,int b){return a>b?a:b;};
int num,n,p,sum[1000001],sp[1000001];
int getL(int n)
{
    int l=-2147483647;
    for(int i=1;i<=n;++i)
        for(int j=0;j<i;++j)
            l=max(l,sum[i]-sum[j]);
    return l;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>p;
    for(int i=1;i<=n;++i)
    {
            scanf("%d",&num);
            sum[i]=sum[i-1]+num;
            sp[i]=getL(i);
            if(i==1)sp[1]=num;
//cout<<"sum["<<i<<"]="<<sum[i]<<endl;
//cout<<"sp["<<i<<"]="<<sp[i]<<endl;
    }
    int ans=0;
    sum[1]=sp[1];
    int ms=sum[1],msx=sum[1]+sp[1];;
    bool mn=true;
    for(int i=2;i<=n;++i)
    {
            ms=max(ms,sum[i-1]+sp[i-1]);
            msx=max(msx,sum[i-1]+sp[i-1]);
            if(msx>0)mn=false;
            sum[i]=msx;
//cout<<"sum["<<i<<"]="<<sum[i]<<endl;
    }
    if(mn&&msx>0)cout<<'-';
    cout<<((mn&&msx>0)?(ms%p-p):ms%p)<<endl;     
    //system("pause");  
    fclose(stdin);
    fclose(stdout);
    return 0;
}
