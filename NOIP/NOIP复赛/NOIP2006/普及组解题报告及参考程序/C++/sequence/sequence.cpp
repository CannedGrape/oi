#include<cstdlib>
#include<fstream>
using namespace std;

int main()
{
  ifstream in("sequence.in");
  ofstream out("sequence.out");
  int k,n,i,j,l,t;
  long a[2000];
  long cf(int x,int y);
  in >> k >> n;
  for(i=0;i<=1050;i++)
    a[i]=0;
  for(i=0;i<=10;i++)
    {
      t=cf(2,i);
      a[t]=cf(k,i);
    }
  
  for(i=1,j=1;i<=1000;i++)
    if(a[i]!=0)
      {
        l=a[i];
        j=1;
      }
    else if(a[i]==0)
      a[i]=a[j++]+l;
  out << a[n] << endl;
  
  in.close();
  out.close();
  return 0; 
}

long cf(int x,int y)
{
  int i;
  long q=1;
  if(y==0)
    return 1;
  for(i=1,q=1;i<=y;i++)
    q=q*x;
  return q;
}
