#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;
const int maxh=1000000,maxm=1<<14;
const int INF=0x7fffffff;
struct cc{
   int old;
   int point;
   cc():point(INF){};
};
int n=0;
int ans1=0;
cc zkw[maxm];
int h[maxh];
cc getmin(int s,int t)
{
   // int ans=INF;
    cc ans;
    for(s=maxm+s-1,t=maxm+t+1;s^t^1;s>>=1,t>>=1)
       {
            if(!(s&1)){if(zkw[s^1].point<ans.point)ans=zkw[s^1];}
            if(t&1){if(zkw[t^1].point<ans.point)ans=zkw[t^1];}
       }
    return ans;
}
void buildzkw(int s,int t)
{
   int i;
   for(s=(maxm+s)>>1,t=(maxm+t)>>1;s!=0 &&t!=0;s>>=1,t>>=1)
     for(i=s;i<=t;i++)
        zkw[i]=zkw[i+i].point<zkw[i+i+1].point?zkw[i+i]:zkw[i+i+1];
        //,cout<<zkw[i+i].point<<" "<<zkw[i+i+1].point;
}
void dfs(int top,int tail,int ord);
int init()
{
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
           scanf("%d",&zkw[maxm+i].point),zkw[maxm+i].old=i;
        buildzkw(1,n);
        dfs(1,n,0);
}
void dfs(int top,int tail,int ord)
{
     if(top<1|| tail>n) return ;if(top>tail)return;
    //cout<<top<<" "<<tail<<endl;
      cc temp=getmin(top,tail);
   //   cout<<temp.point<<" "<<ord<<endl;
     ans1+=(temp.point-ord);
     ord+=temp.point-ord>0?:temp.point,0;
     dfs(top,temp.old-1,ord);
     dfs(temp.old+1,tail,ord);
}
int main()
{
   freopen("block.in","r",stdin);
   freopen("block.out","w",stdout);
    init();
    cout<<ans1<<"\n";
 //   system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
