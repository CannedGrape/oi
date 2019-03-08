 /*---------------------------------------------
    DFS. + Ì°ÐÄ. + HASH.
 ---------------------------------------------*/
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstring>
 #define N 99999997
 #define MAXINT 999999999
 #define SHash 233333
 using namespace std;
 
 int Data1[100001] = {0};
 int Data2[100001] = {0};
 int Or1[100001];
 bool Flag[100001] = {false};
 int Hash[SHash] = {0};
 int n,Min = MAXINT,yu = MAXINT;
 
 int ABS(int a)
 {
    return a>0?a:-a;
 }
 
 bool Hashf()
 {
   int Ans=0;
   for(int i=1,k=1;i<=n;++i,k*=7)
     Ans = Ans+Data1[i]*k+Data2[i]*k*k;
   
   int Key = Ans%SHash;
   for(;Key<=SHash;++Key){
     if(Key == SHash)Key=0;
	 if(Hash[Key]==Ans)return false;
	 if(Hash[Key]==0){
          Hash[Key]  = Ans;	
		  return true;		
	   }
   }
 }
 
 void swap(int *a,int *b)
 {
   int o=*a;
   *a=*b;
   *b=o;
 }
 
 bool Suc()
 {
   bool judge = true;
   for(int i=1;i<=n;++i)
     if(Data2[i] != Or1[Data1[i]]){judge=false;break;}
   return judge;
 }
 
 bool beyong(int a,int b)
 {
   if(b > yu) return false;
     else if(b==yu){
		     if(a > Min) return false;	
           }
   return true;
 }
 
 void min(int a,int b)
 {
      yu = b;
      Min = a;
 }
 
 int DFS(int step,int Yu)
 {
   if(step > N){step=1;Yu++;}
   if(!beyong(step,Yu))return 0;
   if(Suc()){min(step,Yu);return 0;}
   for(int i=1;i<=n-1;++i){
     swap(&Data2[i],&Data2[i+1]);
     if(Hashf())
       DFS(step+1,Yu);
     swap(&Data1[i],&Data2[i+1]);
     }
   for(int i=1;i<=n-1;++i){
     swap(&Data1[i],&Data1[i+1]);
     if(Hashf())
       DFS(step+1,Yu);
     swap(&Data1[i],&Data1[i+1]);
     }
 }
 
 int main()
 {
   freopen("match.in","r",stdin);
   freopen("match.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;++i)
     cin>>Data1[i];
   for(int i=1;i<=n;++i)
     cin>>Data2[i];
     
   for(int i=1,id,min;i<=n;++i){
     min=MAXINT;
     for(int j=1;j<=n;++j){
		if(!Flag[j])
	      if(ABS(Data1[i]-Data2[j])<min){
//			 cout<<min<<endl;
			 min = ABS(Data1[i]-Data2[j]);
			 id = j;
	      }
       }
     Or1[i] = id;
     Flag[id] = true;
	 }
//   for(int i=1;i<=n;++i)
//    cout<<i<<":"<<Or1[i]<<endl;
   
   for(int i=1;i<=n;++i)
     Data1[i] = Data2[i] = i;
   
   DFS(0,0);  
   
   cout<<Min;
   return 0;
 }
