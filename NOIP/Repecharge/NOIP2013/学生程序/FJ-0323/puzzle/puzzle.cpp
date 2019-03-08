//----------------BFS.+Hash.--------------
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define SQue 100000
#define SHash 2333333 
#define N 1777777773
using namespace std;

int map[31][31] = {0};
int Que[SQue][31][31] = {0};
int Head = 0,Tail = 0;
int Hash[SHash] = {0};
int Dirx[4] = {0,1,0,-1};
int Diry[4] = {1,0,-1,0};
bool Flag[31][31] = {false};
int n,m,q;
int EX,EY,SX,SY,TX,TY;

void Swap(int *a,int *b)
{
  int o = *a;
  *a = *b;
  *b = o;
}
bool Hashf(int a[][31])
{
  int Ans = 0;
  for(int i=1,h=1,temp;i<=n;++i,h*=10){
    temp = 0;
    for(int j=1,k=1;j<=m;++j,k*=3){
	   temp= (temp+a[i][j]*k)%N;
     }
    Ans =(Ans+temp*h)%N;
   }
//  printf("Hash:%d\n",Ans);
  
  int Key=Ans%SHash;
  for(;Key<=SHash;Key++){
	if(Key==SHash)Key=0;
	if(Hash[Key] == Ans)return false;
	if(Hash[Key] == 0){Hash[Key]=Ans;return true;}
  }
}

void enque(int a[][31])
{
//  for(int i=1;i<=n;++i,printf("\n"))
//    for(int j=1;j<=m;++j)
//      printf("%d ",a[i][j]);
//  printf("Enque\n");
  for(int i=0;i<=n;++i)
    for(int j=0;j<=m;++j)
       Que[Tail][i][j] = a[i][j];
  Tail++;
  if(Tail==SQue)Tail = 0; 
}

int deque()
{
  if(Head == Tail)return -1;
//  printf("Deque\n");
  if(Head+1 == SQue){
	 Head = 0;
	 return SQue - 1;
  }
  else {
	 Head++;
	 return Head - 1;
  }
}


int main()
{
  freopen("puzzle.in","r",stdin);
  freopen("puzzle.out","w",stdout);  
  scanf("%d%d%d",&n,&m,&q);
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
       scanf("%d",&map[i][j]);
  
  while(q--){
     scanf("%d%d%d%d%d%d",&EX,&EY,&SX,&SY,&TX,&TY);
	 map[SX][SY]=2;
	 map[EX][EY]=3;
	 bool Or = true;

     enque(map);
	 Flag[EX][EY] = true;	 
	 while(1){                                                 //BFS
       int t=deque();
//       printf("%d\n",t);
       if(t == -1)break;
       int xt,yt;
       if(Que[t][TX][TY] == 2){
	 	  printf("%d\n",Que[t][0][0]);
	  	  Or = false;
	      break;
	   }

	   for(int i=1;i<=n;i++)
	     for(int j=1;j<=m;j++)
		    if(Que[t][i][j] == 3){xt=i;yt=j;break;}
	   for(int i=0;i<4;++i){
//			printf("Now:%d %d %d %d %d\n",i,xt+Dirx[i],yt+Diry[i],Flag[xt+Dirx[i]][yt+Diry[i]],Que[t][xt+Dirx[i]][yt+Diry[i]]);
		 if(xt+Dirx[i] <=n && xt+Dirx[i] >0 && yt+Diry[i] <=m && yt+Diry[i] >0 && !Flag[xt+Dirx[i]][yt+Diry[i]] && Que[t][xt+Dirx[i]][yt+Diry[i]]!=0){
//		    printf("Yes:%d\n",i);		
			Swap(&Que[t][xt][yt],&Que[t][xt+Dirx[i]][yt+Diry[i]]);
			 if(Hashf(Que[t])){
				Flag[xt+Dirx[i]][yt+Diry[i]] = true;
				Que[t][0][0]++;
				enque(Que[t]); 
				Que[t][0][0]--;
			 }
			Swap(&Que[t][xt][yt],&Que[t][xt+Dirx[i]][yt+Diry[i]]); 
		 }
	   }
	 }
	if(Or)printf("-1\n");
    map[SX][SY]=1;
    map[EX][EY]=1;	 
    memset(Flag,false,sizeof(Flag));
  }
  return 0;
}
