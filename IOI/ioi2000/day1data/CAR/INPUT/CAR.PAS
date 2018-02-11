{$A+,B-,D+,E+,F-,G+,I+,L+,N+,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 65520,0,655360}
Program Car;
{
IOI2000 Sample Program
Day 1
Task: Car
Programmer: Shao Zheng
Email: shaoz@sina.com
Date:2000.09.23
Algorithm: Simple Greedy
}
const
  fin='CAR.IN';   {Input File Name}
  fon='CAR.OUT';  {Output File Name}
  MaxCarCount=20010;    {Data Boundary}
  MaxModeCount=120;   {Data Boundary}
  MaxWorkerCount=120; {Data Boundary}

Type
  TState=array[1..MaxCarCount]of byte; {To Store the cars' state}

var
  fi,fo:text;                             {Input and Output File}
  CarCount,ModeCount,WorkerCount:integer;
         {The Number of Cars, Modes and Workers}
  Original,Final:TState;               {Original and Final State}
  NeedPrint:Boolean;

Procedure Sort(var A:TState);          {QuickSort Algorithm}
var
  x,t:byte;
  Procedure qs(l,r:integer);
  var i,j:integer;
  begin
    i:=l;j:=r;
    x:=a[(longint(l)+r)div 2];
    while i<=j do
      begin
        while a[i]<x do inc(i);
        while x<a[j] do dec(j);
        if i<=j then
          begin
            t:=a[i];a[i]:=a[j];a[j]:=t;
            inc(i);dec(j);
          end;
      end;
    if i<r then qs(i,r);
    if l<j then qs(l,j);
  end;

begin
  qs(1,CarCount);
end;

Procedure Init;         {Initialization}
var i:integer;
begin
  assign(fi,fin); assign(fo,fon);
  reset(fi);
  readln(fi,CarCount,ModeCount,WorkerCount);
  for i:=1 to CarCount do read(fi,Original[i]);
  close(fi);
  Final:=Original;
  Sort(Final);
end;

Function Find(carno:integer):integer;
var i,j,k:integer;
begin
  i:=1;j:=CarCount;
  while i<=j do
    begin
      k:=(longint(i)+j)div 2;
      if final[k]=carno then begin find:=k;exit;end;
      if final[k]>carno then j:=k-1 else i:=k+1;
    end;
  {error occured!}
  find:=1;
  writeln('Car No. not Found! Error!');
  readln;
end;

var
  usedslot:array[1..MaxCarCount] of boolean;

Function FindSlot(const now:TState;car:integer):integer;
var i,mid:integer;
begin
  mid:=find(car);
  for i:=mid to carcount do
   if final[i]<>car then break else
    if (now[i]<>car)and not usedslot[i] then
      begin findslot:=i;exit;end;
  for i:=mid-1 downto 1 do
   if final[i]<>car then break else
    if (now[i]<>car)and not usedslot[i] then
      begin findslot:=i;exit;end;
  findslot:=0;
end;

Function GetFirstDif(const now,final:TState):integer;
var i:integer;
begin
  for i:=1 to CarCount do
    if now[i]<>final[i] then
      begin GetFirstDif:=i;exit;end;
  GetFirstDif:=-1;
  {No difference}
end;

var
  ChangeList:array[1..MaxWorkerCount,1..2]of integer;
  ChangeCount:integer;

Procedure Change(var Now:TState;const Final:TState;var rest:integer;dif:integer);
var
  workers:array[1..MaxWorkerCount]of integer;
  j,w,nextcar:integer;
begin
  fillchar(usedslot,sizeof(usedslot),false);
  w:=1;
  workers[w]:=dif;
  usedslot[dif]:=true;
  while (w<rest) do
    begin
      nextcar:=now[workers[w]];
      inc(w);
      workers[w]:=findslot(now,nextcar);
      if workers[w]=0 then
        begin dec(w);break;end;{circle found}
      usedslot[workers[w]]:=true;
    end;
  {Change Now}
  nextcar:=now[workers[w]];
  for j:=w downto 2 do
    begin
      now[workers[j]]:=now[workers[j-1]];
      inc(ChangeCount);
      ChangeList[ChangeCount,1]:=workers[j-1];
      ChangeList[ChangeCount,2]:=workers[j];
    end;
  now[workers[1]]:=nextcar;
  inc(ChangeCount);
  ChangeList[ChangeCount,1]:=workers[w];
  ChangeList[ChangeCount,2]:=workers[1];
  dec(rest,w);
end;

Function Process:integer;
var i,j:integer;
  result:integer;
  dif:integer;
  Now,Last:TState;
  Rest:integer;
begin
  result:=0;
  Now:=Original;
  dif:=GetFirstDif(Now,Final);  {find the first different position in Now and Final}
  while dif<>-1 do
   begin
    Last:=Now;
    Rest:=WorkerCount;
    ChangeCount:=0;
    while (rest>=2)and(dif<>-1) do
      begin
        Change(Now,Final,rest,dif);
        dif:=GetFirstDif(Now,Final);
      end;
    inc(result);
    if needprint then
       begin
         write(fo,ChangeCount);
         for i:=1 to ChangeCount do
           write(fo,' ',ChangeList[i,1],' ',ChangeList[i,2]);
         writeln(fo);
       end;
   end;
  Process:=result;
end;

Type
  TAnswer=Integer;

Var
  Answer,Best,Need:TAnswer;  {Answers}
  t:Integer;
  difcount:integer;
  time:Longint;
BEGIN
  writeln;writeln(fin);   {Input File's Name}
  Init;                   {Initialization}

  time:=meml[$40:$6c];

  {Calculate the limits}
  difcount:=0;
  for t:=1 to CarCount do
    if Original[t]<>Final[t] then inc(DifCount);
  Best:=(DifCount-1) div WorkerCount+1;
  Need:=(DifCount-1) div (WorkerCount-1)+1;

  writeln('Limit:',best);
  writeln('Need:',need);

  {Simple Greedy Algorithm}
  NeedPrint:=false;
  Answer:=Process;

  {Output Answer}
  rewrite(fo);
  writeln(fo,Answer);
  writeln('Answer:',answer);
  NeedPrint:=true;
  Answer:=Process;
  close(fo);

  writeln('Time used:',(Meml[$40:$6c]-time)/18.2:0:2);
END.
