#include<stdio.h>
main()
{
    int n,x,jishuqi=0,a;
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d%d",&n,&x);
    for(a=1;a<=n;a++)
     {while(a>0)
       if(a%10==x)
        {jishuqi++;
         a=a/10;
        }
     }
    printf("%d\n",jishuqi);
    return 0;
} 
    
                                                    
