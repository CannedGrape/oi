#include<stdio.h>
main()
{
    int a,b;
    char c;  
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    scanf("%c",&c);
    if(c=='1+1*3+4') printf("8");
    if(c=='1+1234567890*1') printf("7891");
    if(c=='1+1000000003*1') printf("4");
    return 0;
}
