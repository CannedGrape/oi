#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int tong[100000];
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    memset(tong,0,sizeof(tong));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int s,k;
        cin>>s;
        for(int j=1;j<=s;++j)
        {
            cin>>k;
            ++tong[k];
        }
    }
    int Maxvalue=0;
    for(int i=1;i<=n;++i)
    if(tong[i]>Maxvalue)Maxvalue=tong[i];
    cout<<Maxvalue;
    fclose(stdin);fclose(stdout);
}
    
