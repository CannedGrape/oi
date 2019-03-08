#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int mod=99999997;
int n;
int a[100010],b[100010];
int c[100010],d[100010];
int nb[100010];
map<int , int>ma;      // weizhi  m[number]=address
map<int , int>pa,pb;   // paiming p[paimin]=number
void qsorta(int l,int r){
     int i=l,j=r,mid=a[(l+r)/2];
     while(i<=j){
         while(a[i]<mid)i++;
         while(a[j]>mid)j--;
         if(i<=j){
             swap(c[i],c[j]);
             swap(a[i++],a[j--]);}
     }
     if(i<r) qsorta(i,r);
     if(l<j) qsorta(l,j);
}
void qsortb(int l,int r){
     int i=l,j=r,mid=b[(l+r)/2];
     while(i<=j){
         while(b[i]<mid)i++;
         while(b[j]>mid)j--;
         if(i<=j){
             swap(d[i],d[j]);
             swap(b[i++],b[j--]);}
     }
     if(i<r) qsortb(i,r);
     if(l<j) qsortb(l,j);
}
void init(){
     scanf("%d",&n);
     for(int i=1;i<=n;i++) scanf("%d",&a[i]);
     for(int i=1;i<=n;i++){
         scanf("%d",&b[i]);
         d[i]=i; nb[i]=b[i];
         c[i]=i;
     }
}
void inmap(){
     for(int i=1;i<=n;i++)
     {
         ma[a[i]]=c[i];
         pa[i]=a[i];
         pb[b[i]]=i;
     }
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

int tot,from=1,to,ret,x;
struct node
{
       int l,r;        // son
       int left,right; //length
       int add;
}t[500010];
void build(int l,int r)
{
     tot++;
     t[tot].left=l;
     t[tot].right=r;
     if(l!=r)
     {
         int flag=tot;
         int mid=(l+r)/2;
         t[flag].l=tot+1;
         build(l,mid);
         t[flag].r=tot+1;
         build(mid+1,r);
     }
}
void insert(int num)
{
     if(from<=t[num].left&&to>=t[num].right) t[num].add++;
     else
     {
         if(t[num].l) insert(t[num].l);
         if(t[num].r) insert(t[num].r);
     }
}
void get(int num)
{
     if(t[num].left<=x&&x<=t[num].right)
     {
         ret+=t[num].add;
         if(t[num].l) get(t[num].l);
         if(t[num].r) get(t[num].r);
     }
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void work()
{
    int i,ans=0,add;
    int ada,adb; //address
    int nua,nub; //number
    for(i=1;i<=n;i++) 
    {
        adb=i;
        nub=nb[i];
        nua=pa[pb[nub]];
        ada=ma[nua];
        
        to=ada-1;  insert(1);   // add move
        ret=0; x=ada; get(1);  // get move
        add=(ada-adb+ret);
        ans=(ans+add)%mod;
    }
    cout<<ans<<endl;
}
int main()
{
    
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    
    init();
    qsorta(1,n);
    qsortb(1,n);
    build(1,n);
    inmap();
    work();
    return 0;
}

/*
4
2 3 1 4
3 2 1 4

4
1 3 4 2
1 7 2 4

8
1 5 87 21 876 51 789 2
12 68 213 78 1 87 2 787
*/
