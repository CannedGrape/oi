#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
#define ll long long
#define mod 99999997
#define MAXN 200005
int n,a[MAXN],b[MAXN],res[MAXN],num[MAXN];
int cnt;
bool vis[MAXN]={};
inline bool cmp(int x,int y)
{
       return (ll)a[x]*b[num[x]]+(ll)a[y]*b[num[y]]<(ll)a[x]*b[num[y]]+(ll)a[y]*b[num[x]];
}
/*inline bool cmp(int i,int ma,int mb)
{
       return (ll)a[i]*b[res[i]]+(ll)ma*mb>(ll)a[i]*mb+(ll)ma*b[res[i]];
}
void qsort(int head,int tail)
{
     register int i=head,j=tail,mx=(i+j)/2;
     int ma=a[mx],mb=b[res[mx]];
     while(i<=j){
         while(cmp(i,ma,mb)&&i<j)
           i++;
         while(!cmp(j,ma,mb)&&i<j)
           j--;
         if(i<=j)
           swap(res[i++],res[j--]);
     }
     if(i<tail)
       qsort(i,tail);
     if(j>head)
       qsort(head,j);
}*/
inline void init()
{
      register int i;
      scanf("%d",&n);
      for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
      for(i=1;i<=n;i++){
          num[i]=i;
          scanf("%d",&b[i]);
      }
      sort(num+1,num+n+1,cmp);
}
inline int Topo(int x)
{
       int l=-1,r=-1,pos=x;
       while(num[pos]!=x){
           ++cnt;
           vis[pos]=true;
           if(l==-1||l>pos)
             l=pos;
           if(r==-1||r<pos)
             r=pos;
           pos=num[pos];
       }
       ++cnt;
       vis[pos]=true;
       if(l==-1||l>pos)
         l=pos;
       if(r==-1||r<pos)
         r=pos;
       //cout<<cnt<<" "<<r-l+1<<endl;
       return r-l+1;
}
inline void solve()
{
      register int i,len;
      ll ans=0;
      for(i=1;i<=n;i++)
        if(!vis[i]&&i!=num[i]){
            cnt=0;
            len=Topo(i);
            if(cnt==2)
              ans=(ans+len-1)%mod;
            else
              ans=(ans+((ll)(cnt-1)*(len-2)%mod))%mod;
        }
      printf("%lld\n",ans);
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    init();
    solve();
    fclose(stdout);
    fclose(stdin);
    //system("pause");
    return 0;
}
/*
4
2 3 1 4 
3 2 1 4

4
1 3 4 2
1 7 2 4

5
1 2 5 4 3
3 1 2 5 4

*/
