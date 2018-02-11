 /*-------------------------------------
      Dfs.
 -------------------------------------*/
 
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstring>
 #define MAX(a,b) a>b?a:b
 #define MIN(a,b) a<b?a:b
 #define MAXINT 999999999
 using namespace std;
 
 int map[10001][10001];
 bool Flag[10001] = {false};
 bool Or;
 int end;
 int n,m;
 
 int Dfs(int id,int min)
 {
    if(id == end) {Or=true;return min;}
	for(int i=1;i<=n;++i){
	   if(map[id][i] != -1 && !Flag[i]){
		  if(map[id][i]<min)min = map[id][i];
//		  cout<<id<<' '<<i<<' '<<min<<endl;
		  Flag[id] = true;
		  min = MIN(min,Dfs(i,min));
		  Flag[id] = false;
	   }
	}
	return min;
 }
 
 int main()
 {
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
        map[i][j] = -1; //init

	for(int i=1,x,y,z;i<=m;++i){
    	cin>>x>>y>>z;
    	map[y][x]=map[x][y]=z;
	  }

    int q;
    cin>>q;
	for(int i=1,x,y;i<=q;++i){
	   cin>>x>>y;
	   end = y;
	   int max = 0;
	   Or=false;
	   Flag[x] = true;
	   for(int j=1;j<=n;++j){
		  if(map[x][j] != -1){
			 Flag[j] = true;
			 max = MAX(max,Dfs(j,map[x][j]));
			 Flag[j] = false;
		  }	  
	   }
	   Flag[x] = false;
	   if(Or)
	     cout<<max<<endl;
	    else
		 cout<<"-1"<<endl; 	   
	} 
	return 0;
 }
