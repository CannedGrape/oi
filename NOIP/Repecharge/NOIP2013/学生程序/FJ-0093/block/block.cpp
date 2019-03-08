#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
int n,blocks[100002]={},ans=0;
void solve(int l,int r,int h)
{ int _,m=10002,minnum;
  if(r-l<3)
  { if(r-l==1)
     return;
    if(r-l==2)
    { ans+=blocks[l+1]-h;
      return;
    }
    return;
  }
  for(_=l+1;_<r;_++)
   if(blocks[_]<m)
   { m=blocks[_];
     minnum=_;
   }
  ans+=m-h;
  solve(l,minnum,m);
  solve(minnum,r,m);
}
int main()
{ freopen("block.in","r",stdin);
  freopen("block.out","w",stdout);
  cin>>n;
  int _;
  for(_=1;_<=n;_++)
   cin>>blocks[_];
  solve(0,n+1,0);
  cout<<ans<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
