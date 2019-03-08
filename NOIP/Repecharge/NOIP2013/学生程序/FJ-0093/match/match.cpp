#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
int n,a[100000]={},b[100000]={},a2[100000]={},b2[100000]={},sortarray[100000][2]={},ans=0;
bool found[100000]={};
const int m=99999997;
void solve(int x)
{ int _,find=0;
  for(_=0;_<n;_++)
   if(a2[_]==b2[x])
    break;
  found[_]=1;
  ans+=_;
  while(_<n-1)
  { _++;
    if(found[_])
     find++;
  }
  ans+=find-x;
  ans%=m;
}
void sort_in_b(int x)
{ int _,__;
  for(_=0;_<x;_++)
   if(b[x]<b[sortarray[_][1]])
   { for(__=x;__>_;__--)
     { sortarray[__][0]=sortarray[__-1][0];
       sortarray[__][1]=sortarray[__-1][1];
     }
     sortarray[_][0]=b[x];
     sortarray[_][1]=x;
     return;
   }
  sortarray[x][0]=b[x];
  sortarray[x][1]=x;
}
void sort_in_a(int x)
{ int _,__;
  for(_=0;_<x;_++)
   if(a[x]<a[sortarray[_][1]])
   { for(__=x;__>_;__--)
     { sortarray[__][0]=sortarray[__-1][0];
       sortarray[__][1]=sortarray[__-1][1];
     }
     sortarray[_][0]=a[x];
     sortarray[_][1]=x;
     return;
   }
  sortarray[x][0]=a[x];
  sortarray[x][1]=x;
}
int main()
{ freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  cin>>n;
  int _;
  for(_=0;_<n;_++)
  { cin>>a[_];
    sort_in_a(_);
  }
  for(_=0;_<n;_++)
   a2[sortarray[_][1]]=_;
  for(_=0;_<n;_++)
  { sortarray[_][0]=0;
    sortarray[_][1]=0;
  }
  for(_=0;_<n;_++)
  { cin>>b[_];
    sort_in_b(_);
  }
  for(_=0;_<n;_++)
   b2[sortarray[_][1]]=_;
  for(_=0;_<n;_++)
   solve(_);
  cout<<ans<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
