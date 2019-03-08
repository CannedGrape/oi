#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int sum=0;
void chuli(int shuzi,int ceshi)
{
    if((shuzi<10)&&(shuzi==ceshi))
        sum++;
    if((shuzi>=10)&&(shuzi<100))
      {if(shuzi%10==ceshi)
           sum++;
       if((shuzi-shuzi%10)/10==ceshi)
           sum++;
           }
    if((shuzi>=100)&&(shuzi<1000))
       if(shuzi%10==ceshi)
          sum++;
       if((shuzi%100-shuzi%10)/10==ceshi)
          sum++;
       if((shuzi-shuzi%100)/100==ceshi)
          sum++;
}
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int i,shuzi,ceshi;
    cin>>shuzi>>ceshi;
    for(i=1;i<=shuzi;i++)
        chuli(i,ceshi);
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

    
    
    
    
