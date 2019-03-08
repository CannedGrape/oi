#include<iostream>
#include<cstdio>
using namespace std;
long long int nn,i;
long int p,t[2],s[2],ans;
int n[1];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>nn>>p;
    cin>>n[0];
    t[0]=n[0];
    s[0]=n[0];
    if(t[0]+n[1]>t[0])t[1]=t[0]+n[i];
    else t[1]=t[0];
    s[1]=t[0]+s[0];
    if(s[0]>s[1])ans=s[0];
    else ans=s[1];
    cout<<s[0]<<" "<<s[1]<<" "<<" "<<ans<<endl;
    for(i=1;i<nn;i++)
    {
      cin>>n[0];
      if(i>1)
      {t[0]=t[1];
      s[0]=s[1];}
      if(t[0]+n[0]>t[0])t[1]=t[0]+n[0];
      else t[1]=t[0];
      if(s[0]>0)s[1]=t[0]+s[0];
      else s[1]=s[0];//t[i-1]+s[i-1]>t[i-1]
      if(ans<s[1])ans=s[1];cout<<s[0]<<" "<<s[1]<<" "<<" "<<ans<<endl;
    }
    if(ans<0){ans*=-1;ans%=p;ans*=-1;}else ans%=p;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
                   
