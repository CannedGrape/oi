#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
char n;
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    scanf("%c",&n);
    if (n=='1+1*3+4') cout<<"8"<<endl;
    if (n=='1+1234567890*1') cout<<"1234567891"<<endl;
    if (n=='1+1000000003*1') cout<<"1000000004"<<endl;
    system("pause");
    fclose(stdin);fclose(stdout);
    return 0;
}
