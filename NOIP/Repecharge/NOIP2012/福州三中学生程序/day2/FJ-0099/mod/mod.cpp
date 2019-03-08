#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{   freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    int a,b,c,d,e,i,so,st;long long s;
    scanf("%d %d",&a,&b);
    if(a%b==1){printf("1\n");fclose(stdin);fclose(stdout);return 0;}
    c=b%a;d=b/a;
    if((c==1)||(b-c==1)){printf("%d\n",(a-c)*(b/a)+1);fclose(stdin);fclose(stdout);return 0;}
    for(i=1;i<=b;i++)
      {s=i*a;
       if(s%c==1)
       {so=i;break;}
      }
    if(d==0){printf("%d\n",so);fclose(stdin);fclose(stdout);return 0;}
    e=c+a;
    for(i=so+1;i<=b;i++)
      {s=i*a;
       if(s%e==1)
        {st=i;break;}
      }
    printf("%d\n",(st-so)*d+so);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
