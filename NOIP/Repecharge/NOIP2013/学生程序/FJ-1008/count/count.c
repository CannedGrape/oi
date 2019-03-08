#include<stdio.h>
int myi,myj,myn,myx,mynum=0;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d %d",&myn,&myx);
    for(myi=1;myi<=myn;myi++)
    {
       myj=myi;
       while(myj>=1)
       {
          if(myj%10==myx) mynum++;
          myj=myj/10;
       }
    }
    printf("%d\n",mynum);
    return 0;
}
