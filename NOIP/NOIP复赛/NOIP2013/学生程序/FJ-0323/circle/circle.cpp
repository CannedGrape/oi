 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstring>
 using namespace std;

int main()
{ 
  freopen("circle.in","r",stdin);
  freopen("circle.out","w",stdout);
  int n,m,k,x;
  cin>>n>>m>>k>>x;
  int Circle = 1;
  for(int i=0;i<k;++i)
    Circle *= 10;
  
  for(int i=0;i<Circle;++i)
     x = (x+m)%n;

  cout<<x;
  return 0;
}
