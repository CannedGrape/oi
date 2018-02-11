#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long ans;
int n;
int a[100001];

void file_open()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
}

void file_close()
{
    fclose(stdin); fclose(stdout);
}

int init()
{
    int now=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      if (a[i]>now) ans+=a[i]-now;
      now=a[i];
    }
    return 0;
}

int work()
{
    cout<<ans<<endl;
    return 0;
}

int main()
{
    file_open();
    init();
    work();
    //system("pause");
    file_close();
    return 0;
}
