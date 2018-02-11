#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
string str;
int Mod=10000;
int a[1000010];
bool b[100010];
int bo[100010];//0===+;1===*;
int Pow(int x,int y)
{
    int s=1;
    for(int i=1;i<=y;++i)
    s*=x;
    return s;
}
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    cin>>str;
    int len=str.size();
    int sum=0,spit=0;
    for(int i=0;i<=len;++i)
    if(str[i]=='+'||str[i]=='*')
    {
        ++spit;
        bo[spit]=(str[i]=='+')?0:1;
        int k=i-1,j=-1;
        ++sum;
        while(((int)(str[k])>=48)&&((int)(str[k])<=57))
        {
            ++j;
            a[sum]+=((int)(str[k])-48)*Pow(10,j);
            --k;
        }
    }
    int kk=len-1,jj=-1;
    sum++;
    while(((int)(str[kk])>=48)&&((int)(str[kk])<=57))
    {
        ++jj;
        a[sum]+=((int)(str[kk])-48)*Pow(10,jj);
        --kk;
    }
    long long ans=0;
    for(int i=1;i<=spit;++i)
    if(bo[i]&&!b[i])
    {
        long long sub=a[i]%Mod;
        b[i]=1;
        int kkk=i+1; 
        while(bo[kkk]&&!b[kkk])
        {
            sub=(sub*a[kkk])%Mod;
            b[kkk]=1;
            ++kkk;
        }
        sub=(sub*a[kkk])%Mod;
        b[kkk]=1;
        ans=(ans+sub)%Mod;
    }
    for(int i=1;i<=sum;++i)
    if(!b[i])ans=(ans+a[i])%Mod;
    cout<<ans;
    fclose(stdin);fclose(stdout);
}
