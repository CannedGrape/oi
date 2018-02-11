#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int i,j,n,x,y,m,v,q,p,w,g,t,h,d;
int a[100001],b[100001],c[100001];
int zx(int i,int j)
{   if(i>=j)  return i-j;
    else  return j-i;
}
int main()
{   freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
       cin>>a[i];
    for(i=1;i<=n;i++)
       cin>>b[i];
    for(i=1;i<=n;i++)
       c[i]=zx(b[i],a[i]);
	x=1;y=n;h=0;
    while(a[x]==b[x] && x<=n)  x++;
    while(a[y]==b[y] && y>=1)  y--;
    for(i=x;i<y;i++)
       { for(j=x;j<=y;j++)
           {if(c[j]>m)
             { m=c[j];
               v=j;
		     }
	       }      
		 if(v==x)
           { q=zx(b[i],a[i]);
             p=zx(b[i+1],a[i]);
             if(p<q)
               { t=b[i];b[i]=b[i+1];b[i+1]=t;
			     h++;
			     c[i]=zx(b[i],a[i]);
			     c[i+1]=zx(b[i+1],a[i+1]);
			   }
		   }
		 if(v==y)
		   { q=zx(b[i],a[i]);
             p=zx(b[i-1],a[i]);
             if(p<q)
               { t=b[i];b[i]=b[i-1];b[i-1]=t;
			     h++;
			     c[i]=zx(b[i],a[i]);
			     c[i-1]=zx(b[i-1],a[i-1]);
			   }
		   }
		 else
		 {  g=zx(b[i-1],a[i]);
			q=zx(b[i],a[i]);
            p=zx(b[i+1],a[i]);
            if(g<g && g<p)
              { t=b[i];b[i]=b[i-1];b[i-1]=t;
			    h++;
			    c[i]=zx(b[i],a[i]);
			    c[i-1]=zx(b[i-1],a[i-1]);
			  }
			if(p<q && p<g)
              { t=b[i];b[i]=b[i+1];b[i+1]=t;
			    h++;
				c[i]=zx(b[i],a[i]);
			    c[i-1]=zx(b[i-1],a[i-1]);
			  }
			    
		 }
	   }
	h=h%99999997;
    cout<<h<<endl;
    

    return 0;
}
