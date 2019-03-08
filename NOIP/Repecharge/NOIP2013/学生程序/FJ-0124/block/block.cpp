#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
    int i,n,h[100001],a[100001],t=1,ans=0,max=0,c,j,d=0;
    cin>>n;
    for(i=1;i<=n;i++)
     {cin>>h[i];
     a[i]=h[i];}
     sort(a+1,a+1+n);
     for(i=2;i<=n;i++)
      {
        if(a[i]==a[1])t++;
        if(a[i]!=a[1])break;
      }
     if( (a[1]==h[1]&&t==1) || (a[1]==h[n]&&t==1) || (a[1]==h[n]&&a[1]==h[1]&&t==2)||t==n)
     {cout<<a[n];
       return 0;}
	 c=t;
    if(h[1]==a[1])
    {t--;c--;
       for(i=2;i<=n;i++)
        {if(h[i]>max&&h[i]>a[1])max=h[i];
         if(i==n&&t==0)ans=max+ans-a[1];
         if(h[i]==a[1])
         {ans+=max;      
          max=0;
          t--;
		 
		  if(h[i+1]==a[1]||(i==n&&h[i]==a[1]))c--;}
		  if(t==0&&i<n&&ans==0){cout<<a[n]; return 0;}
		  if(c==n-i&&i<n)
			  {for(j=i;j<=n;j++)
				  { if(h[j]==a[1])d++;}
				  if(d==c){cout<<a[n]; 
				  return 0;}
			  }
         }
         }  
    if(h[1]!=a[1])
	 {for(i=1;i<=n;i++)
        {if(h[i]>max&&h[i]>a[1])max=h[i];
         if(i==n&&t==0)ans=max+ans;
         if(h[i]==a[1])
         {ans+=max;      
          max=0;
          t--;
		  if(h[i+1]==a[1]||(i==n&&h[i]==a[1]))c--;}
		  else if(t==0&&i<n&&ans==0){cout<<a[n]; return 0;}
		  else if(c==n-i&&i<n) 
			  {for(j=i;j<=n;j++)
				  { if(h[j]==a[1])d++;}
				  if(d==c){cout<<a[n]; 
				  return 0;}
			  }
         }
	 }
    cout<<ans-(c*a[1]);
    return 0;
    
}
