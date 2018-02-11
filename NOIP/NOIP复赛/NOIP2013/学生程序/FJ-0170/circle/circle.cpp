#include <fstream>

using namespace std;
ifstream fin ("circle.in" );
ofstream fout("circle.out");

typedef long long lint;

lint N,M,K,X;

lint pow(lint base, lint idx)
{
    lint r=1, j=base;
    for(lint i=1;i<=idx;i<<=1)
    {
        if(idx&i)
            r*=j;
        j*=j;
    }
    return r;
}

int main()
{
    fin>>N>>M>>K>>X;
    lint ans = pow(10,K);
    ans = ans*M%N;
    ans = (ans+X)%N;
    fout<<ans<<endl;
    return 0;
}
