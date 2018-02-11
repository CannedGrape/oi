/*
IOI2000 Sample Program
Day 1
Task: Car
Programmer: Shao Zheng
Email: shaoz@sina.com
Date:2000.09.23
Algorithm: Simple Greedy
*/

/* USE COMPACT MODEL TO COMPILE */

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>


#define fin "CAR.IN"
#define fon "CAR.OUT"
#define MaxCarCount 20010    //Data Boundary
#define MaxModeCount 120   //Data Boundary
#define MaxWorkerCount 120  //Data Boundary

typedef unsigned char TState[MaxCarCount+1]; //To Store the cars' state

FILE*fi,*fo;    //Input and Output File
int CarCount,ModeCount,WorkerCount; //The Number of Cars, Modes and Workers
TState Original,Final;              //Original and Final State
int NeedPrint;
int ChangeCount;
int ChangeList[MaxWorkerCount+1][2];

int x,t;
void qs(TState A,int l,int r){
 int i=l,j=r;
 x=A[((long)l+r)/2];
 while (i<=j){
   while (A[i]<x) i++;
   while (x<A[j]) j--;
   if (i<=j){
    t=A[i];A[i]=A[j];A[j]=t;
    i++;j--;
   }
 }
 if (i<r) qs(A,i,r);
 if (l<j) qs(A,l,j);
}

void Sort(TState A){      //QuickSort Algorithm
 qs(A,1,CarCount);
}

void Init(void){         //Initialization
 int i;
 fi=fopen(fin,"r");
 fo=fopen(fon,"wt");
 fscanf(fi,"%d%d%d",&CarCount,&ModeCount,&WorkerCount);
 for (i=1;i<=CarCount;i++)
   {fscanf(fi,"%d",&Original[i]);Final[i]=Original[i];}
 fclose(fi);
 Sort(Final);
}

int Find(int carno){
 int i=1,j=CarCount,k;
 while (i<=j){
   k=((long)i+j)/2;
   if (Final[k]==carno) return k;
   if (Final[k]>carno) j=k-1; else i=k+1;
 }
 //error occured!
 printf("Car No. not Found! Error!");
 exit(0);
 return 0;
}

char usedslot[MaxCarCount];

int FindSlot(TState now,int car){
 int i,mid;
 mid=Find(car);
 for (i=mid;i<=CarCount;i++)
   if (Final[i]!=car) break;
   else if ((now[i]!=car)&&!usedslot[i]) return i;
 for (i=mid-1;i>=1;i--)
   if (Final[i]!=car) break;
   else if ((now[i]!=car)&&!usedslot[i]) return i;
 return 0;
}

int GetFirstDif(TState now,TState final){
 int i;
 for (i=1;i<=CarCount;i++)
   if (now[i]!=final[i]) return i;
 return -1;  //No difference
}

void Change(TState Now,int*rest,int dif){
 int workers[MaxWorkerCount+1];
 int j,w=1,nextcar;
 memset(usedslot,0,sizeof(usedslot));
 workers[w]=dif;
 usedslot[dif]=1;
 while (w<*rest){
  nextcar=Now[workers[w++]];
  workers[w]=FindSlot(Now,nextcar);
  if (workers[w]==0){w--;break;} //circle found
  usedslot[workers[w]]=1;
 }
 //Change Now
 nextcar=Now[workers[w]];
 for (j=w;j>=2;j--) {
  ChangeList[ChangeCount][0]=workers[j-1];
  ChangeList[ChangeCount][1]=workers[j];
  ChangeCount++;
  Now[workers[j]]=Now[workers[j-1]];
 }
 Now[workers[1]]=nextcar;
 ChangeList[ChangeCount][0]=workers[w];
 ChangeList[ChangeCount][1]=workers[1];
 ChangeCount++;
 (*rest)-=w;
}

int Process(void){
 int i,j;
 int result=0,dif;
 TState Now;
 int rest;
 for (i=1;i<=CarCount;i++) Now[i]=Original[i];
 dif=GetFirstDif(Now,Final); //find the first different position in Now and Final
 while (dif!=-1){
  rest=WorkerCount;
  ChangeCount=0;
  while ((rest>=2)&&(dif!=-1)){
   Change(Now,&rest,dif);
   dif=GetFirstDif(Now,Final);
  }
  result++;
  if (NeedPrint){
   fprintf(fo,"%d",ChangeCount);
   for (i=0;i<ChangeCount;i++)
    fprintf(fo," %d %d",ChangeList[i][0],ChangeList[i][1]);
   fprintf(fo,"\n");
  }
 }
 return result;
}


int Answer,Best,Need; //Answers
int i,t;
int DifCount;

main(){
  Init();               //Initialization

  //Calculate the limits
  DifCount=0;
  for (t=1;i<=CarCount;i++)
   if (Original[t]!=Final[t]) DifCount++;
  Best=(DifCount-1)/WorkerCount+1;
  Need=(DifCount-1)/(WorkerCount-1)+1;

  //Simple Greedy Algorithm
  NeedPrint=0;
  Answer=Process();

  //Output Answer
  fprintf(fo,"%d\n",Answer);
  NeedPrint=1;
  Answer=Process();
  fclose(fo);
  return 0;
}
