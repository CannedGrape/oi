#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
bool used[1001];
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    cin>>n>>m;
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
            int a;
            scanf("%d",&a);
            used[a]=true;
    }
    int ans=1;
    for(int i=2;i<=m;++i)
    {
            int t;
            bool added=false;
            scanf("%d",&t);
            for(int i=1;i<=t;++i)
            {
                    int a;
                    scanf("%d",&a);
                    if((!used[a])&&(!added))
                    {

                                           bool passed=false;
                                           //for(int i=1;i<a;++i){if(used[i]){passed=true;break;}}
                                           //for(int i=a+1;i<=n;++i)if(used[i]){passed=true;break;}
                                           if(!passed){added=true;
                                           //used[a]=true;
                                           ++ans;}
                    }
                    used[a]=true;
            }
    }
    for(int i=1;i<=n;++i){if(!used[i]){
            ++ans;
            break;}
}
    cout<<ans;
 //   system("pause");
 //unzipPassword=shi13xian11China09Meng
   fclose(stdin);
    fclose(stdout);
    return 0;
}
