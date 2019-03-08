#include<iostream>
#include<stdin.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    long i,k,n,m,w,q;
    w=0;
    q=0;
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    cin>>n>>m;
    long s[m+1],t[m+1];
    long long r[n+1],d[m+1];
    for(i=1;i<=n;i++)
       cin>>r[i];
    for(i=1;i<=m;i++)
       cin>>d[i]>>s[i]>>t[i];
    while(w==0)
    {  for(i=1;i<=m;i++) 
       {  q++;
          for(k=s[i];k<=t[i];k++)
          {   r[k]=r[k]-d[i];
              if(r[k]<0)
              w=-1;
		  }
       }
    }
    q--;
    if (w==0)
    cout<<w;
    if (w==-1)
    cout<<w<<endl<<q;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
