#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int maxn=1;
int h[1001],l[1001],r[1001];
void remove(int x)
{
     l[r[x]]=l[x];
     r[l[x]]=r[x];
     }
void recover(int x)
{
     l[r[x]]=x;
     r[l[x]]=x;
     }
void dfs()
{
     bool b=true;
     int sum=0;
     int i;
     for(i=r[r[0]];i!=-1;i=r[r[i]])
     {
     if(h[l[i]]<h[i]&&h[r[i]]<h[i]){}
     else if(h[l[i]]>h[i]&&h[r[i]]>h[i]){}
     else
     {b=false;break;}
     if(r[i]==-1)break;
     }
     if(b)
     {
     for(i=r[0];i!=-1;i=r[i])sum++;
     if(sum>maxn)maxn=sum;
     return ;
     }
     else
     for(i=r[0];i!=-1;i=r[i])
     {
     remove(i);
     dfs();
     recover(i);
     }
}     
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    if(n==1)cout<<"0"<<endl;
    else
    {
    memset(h,0,sizeof(h));
    int i;
    for(i=1;i<=n;i++)
    {cin>>h[i];l[i]=i-1;r[i]=i+1;}
    r[0]=1;
    r[n]=-1;
    dfs();
    cout<<maxn<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
    
    
    
