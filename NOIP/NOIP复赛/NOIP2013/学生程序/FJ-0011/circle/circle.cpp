/* circle.cpp NOIP 2013 day1.A
   By Sweetdumplings @ FZYZ / Fudan University
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,k,x;
long long Pow(long long k)
{
    if (k==0) return 1;
    if (k==1) return 10%n;
    if (k==2) return 100%n;
    long long t=Pow(k>>1);
    t=t*t%n;
    if (t&1)
    {
        return t*10%n;    
    }else
    {
        return t;
    }
}
int main()
{
    ifstream fin("circle.in");
    ofstream fout("circle.out");
    fin >> n >>m >>k >>x;
    long long Ans=m;
    Ans*=Pow(k);
    Ans%=n;
    Ans+=x;
    Ans%=n;
    fout << Ans <<endl;
    fin.close();
    fout.close();
    return 0;
}
