#include <fstream>
using namespace std;
int main()
{
  ifstream fin("random.in");
  ofstream fout("random.out");
  int a[1001],n,t,i,q;
  memset(a,0,sizeof(a));
  fin >> n;
  q=n;
  for(i=1;i<=n;i++)
    {
       fin >> t;
       a[t]++;
       if(a[t]>1)
          q--;
    }
  fout << q << endl;
  for(i=1;i<=1000;i++)
    if (a[i])
      fout << i << " ";
  fout <<"\n";
  fin.close();
  fout.close();
  return 0;
}
