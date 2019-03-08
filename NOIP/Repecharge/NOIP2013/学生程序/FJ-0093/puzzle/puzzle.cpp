#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,q,empty_x,empty_y,start_x,start_y,end_x,end_y,ans=-2;
bool game[30][30]={},oktest[30][30]={},visited[30][30]={},ok;
/*void check(int x,int y,int pre_x,int pre_y)
{ int dir=0;
  visited[x][y]=1;
  if(x>0)
   if(oktest[x-1][y]&&!visited[x-1][y]&&(x-1!=pre_x||y!=pre_y))
   
}*/
bool special()
{ if(start_x==end_x&&start_y==end_y)
  { ans=0;
    return 1;
  }
  if(empty_x==end_x&&empty_y==end_y&&abs(end_x-start_x)+abs(end_y-start_y)==1)
  { ans=1;
    return 1;
  }
  return 0;
}
void solve()
{ int _,__;
  cin>>empty_x>>empty_y>>start_x>>start_y>>end_x>>end_y;
  ok=0;
  ans=-2;
  for(_=0;_<n;_++)
   for(__=0;__<m;__++)
    oktest[_][__]=game[_][__];
  if(special())
  { cout<<ans<<endl;
    return;
  }
  //check(end_x,end_y,end_x,end_y);
  //
}
int main()
{ freopen("puzzle.in","r",stdin);
  freopen("puzzle.out","w",stdout);
  cin>>n>>m>>q;
  int _,__;
  for(_=0;_<n;_++)
   for(__=0;__<m;__++)
    cin>>game[_][__];
  for(_=0;_<q;_++)
   solve();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
