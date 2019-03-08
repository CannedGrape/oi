#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,q,ms/*[50000]*/[3]={},qs/*[30000]*/[2]={},road[10000][10000]={},ans=-1;
bool visited[10000]={};
void solve(int x,int y,int now)
{ int _;
  visited[x]=1;
  if(x==y)
  { ans=max(ans,now);
    visited[x]=0;
    return;
  }
  for(_=0;_<n;_++)
   if(road[x][_]!=-1&&!visited[_])
    solve(_,y,min(now,road[x][_]));
  visited[x]=0;
}
int main()
{ freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
  cin>>n>>m;
  int _,__;
  for(_=0;_<n;_++)
   for(__=0;__<n;__++)
    road[_][__]=-1;
  for(_=0;_<m;_++)
  { for(__=0;__<3;__++)
     cin>>ms/*[_]*/[__];
    ms/*[_]*/[0]--;
    ms/*[_]*/[1]--;
    road[ms/*[_]*/[0]][ms/*[_]*/[1]]=max(road[ms[0]][ms[1]],ms/*[_]*/[2]);
    road[ms/*[_]*/[1]][ms/*[_]*/[0]]=ms/*[_]*/[2];
  }
  cin>>q;
  for(_=0;_<q;_++)
  { for(__=0;__<2;__++)
     cin>>qs/*[_]*/[__];
    qs/*[_]*/[0]--;
    qs/*[_]*/[1]--;
    ans=-1;
    solve(qs[0],qs[1],100008);
    cout<<ans<<endl;
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
