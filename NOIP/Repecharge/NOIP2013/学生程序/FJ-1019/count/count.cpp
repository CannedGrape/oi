#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int a,b;
    unsigned long rst=0;
    char tmp[20];
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a;i++)
    {
        sprintf(tmp,"%d",i);
        for(unsigned int j=0;j<=strlen(tmp)-1;j++)
        {
            if(tmp[j]==b+'0') rst++;
        }
    }
    printf("%ld",rst);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
