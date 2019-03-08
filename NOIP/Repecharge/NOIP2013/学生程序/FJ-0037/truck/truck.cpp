#include<iostream>
#include<queue>;
#include<algorithm>
#include<stdio.h>
using namespace std;
int n;
int m;
int total;
int father[10001];
struct node
{
  int u;
  int v;
  int last;
  int next;
  int solve;
}q[30001];
struct edge
{
  int u;
  int v;
  int value;
}cc[100001];
void add(int a,int b,int c)
{
  total++;
  cc[total].u=a;
  cc[total].v=b;
  cc[total].value=c;
}
int find(int x)
{
  if(x==father[x])
    return x;
  return father[x]=find(father[x]);
}
void merge(int a,int b)
{
  a=find(a);
  b=find(b);
  if(a!=b)
    father[a]=b;
}
void init()
{
  scanf("%d%d",&n,&m);
  int a,b,c;
  for(int i=1;i<=m;i++)
  {
    scanf("%d%d%d",&a,&b,&c);
    add(a,b,c);
  }
}
bool cmp(edge a,edge b)
{
  return a.value>b.value;
}
void work()
{
  sort(cc+1,cc+n+1,cmp);
  for(int i=1;i<=n;i++)
    father[i]=i;
  int q1;
  scanf("%d",&q1);
  for(int i=1;i<=q1;i++)
  {
    scanf("%d%d",&q[i].v,&q[i].u);
    q[i].next=i+1;
    q[i].last=i-1;
    q[i].solve=-1;
  }
  q[q1].next=0;
  int i=1;
  int last_ds;
  while(q1!=0&&i<=m)
  {    
    if(find(cc[i].u)!=find(cc[i].v))
    {
      merge(cc[i].u,cc[i].v);
      for(int j=1;j;j=q[j].next) 
      {
        if(find(q[j].u)==find(q[j].v)&&q[j].solve<cc[i].value)
        {
          q[j].solve=cc[i].value;
          q[q[j].last].next=q[j].next;
          q[q[j].next].last=q[j].last; 
          q1--;
        }
      }
    }
    i++;
  }
}
void out()
{
  int i=1;
  while(q[i].v!=0)
  {
    printf("%d\n",q[i].solve);
    i++;
  }
}
int main()
{
  freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
  init();
  work();
  out();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
