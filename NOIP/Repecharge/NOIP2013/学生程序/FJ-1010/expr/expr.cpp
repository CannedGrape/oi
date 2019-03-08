#include<iostream>
#include<cstdio>
using namespace std;
int max(int a,int b){return a>b?a:b;};
int num[100002];
char x[100001];
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    string exp;
    cin>>exp;
    int size=exp.size();
    int f=0,ans=0,it=0;
    for(int i=0;i<size;++i)
    {
            if(exp[i]=='+'||exp[i]=='*')
            {
                           x[++it]=exp[i];
                           for(int j=max(i-4,f);j<i;++j)
                           {
                               num[it]=num[it]*10+static_cast<int>(exp[j])-static_cast<int>('0');
                           }
                           f=i+1;
            }
    }
    ++it;
    for(int j=max(size-4,f);j<size;++j)
                           {
                               num[it]=num[it]*10+static_cast<int>(exp[j])-static_cast<int>('0');
                           }
    for(int i=1;i<=it-1;++i)
        if(x[i]=='*')
        {
                     num[i+1]=(num[i]*num[i+1])%10000;
                     num[i]=0;
                     x[i]='+';
        }
    for(int i=1;i<=it;++i)ans=(ans+(num[i])%10000)%10000 ;
    cout<<ans;
//system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
