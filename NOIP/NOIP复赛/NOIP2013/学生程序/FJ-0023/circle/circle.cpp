#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long n,m,k,sx;
void file_open()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
}

void file_close()
{
    fclose(stdin); fclose(stdout);
}

int init()
{
    cin>>n>>m>>k>>sx;
    return 0;
}

long long ksm(int x,int y)
{
    if (y==0) return 1;
    if (y==1) return x;
    long long tmp=ksm(x,y/2)%n;
    tmp=tmp*tmp%n;
    if (y%2==1) tmp=tmp*x%n;
    return tmp;
}

int work()
{
    long long tmp=ksm(10,k);
    cout<<(sx+(m%n)*tmp)%n<<endl;
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
