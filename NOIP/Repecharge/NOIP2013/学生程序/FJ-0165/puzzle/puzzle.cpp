#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{int q,i;
 freopen("puzzle.in","r",stdin);
 freopen("puzzle.out","w",stdout);
 cin>>q>>q>>q;
 srand(time(NULL));
 for(i=1;i<=q;i++)
 cout<<rand()%100;
 fclose(stdin);
 fclose(stdout);
 return 0;
    }
