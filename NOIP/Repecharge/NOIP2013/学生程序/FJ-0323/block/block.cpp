//----------DFS. + ºÙ÷¶. + HEU.-------------
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 100000
#define MAXINT 99999999
int Min = MAXINT;
using namespace std;

int Node[N+2] = {0};
int n;

bool Judge()
{
  bool Flag = true;
  for(int i=1;i<=n;++i)
    if(Node[i]!=0){Flag = false;break;}
  return Flag;
}

int Dfs(int step)
{
  if(step>Min)return 0;
  if(Judge()){
      Min = step;
      printf("%d",Min);
      exit(0);
    }
  int Flag = 0;  
    for(int i=1,k;i<=n;++i){
	  if(Node[i] != 0){
	  for(k=1;k<=n;++k)
	     if(Node[i+k] == 0){k--;break;}
	   if(k < Flag)break;
	   Flag = k;
	   for(int j=i;j<=i+k;++j)
	     Node[j]--;
	   Dfs(step+1);
	   for(int j=i;j<=i+k;++j)
	     Node[j]++;

	  }
    }   
  return 0;
}

int main(void)
{
  freopen("block.in","r",stdin);
  freopen("block.out","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;++i)
    scanf("%d",&Node[i]);
  
  Dfs(0);
  return 0;
}
