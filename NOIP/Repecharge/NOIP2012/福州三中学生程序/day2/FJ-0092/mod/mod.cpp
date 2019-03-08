#include<stdio.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	register ll a,b;
    scanf("%lld%lld",&a,&b);
    a%=b;
    for(register ll i=1;;i+=b)
        if(i%a==0)
        {
			printf("%lld\n",(i/a));
			break;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
