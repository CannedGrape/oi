#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
int n,flowers[100000]={},ans=1;
int main()
{ freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  cin>>n>>flowers[0];
  int _;
  if(n<=2)
   cout<<n<<endl;
  else
  { cin>>flowers[1];
    for(_=2;_<n;_++)
    { cin>>flowers[_];
      if((flowers[_]-flowers[_-1])*(flowers[_-1]-flowers[_-2])<0)
       ans++;
    }
    ans++;
    cout<<ans<<endl;
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
