Program Post;
{
IOI2000 Sample Program
Day 2
Task: Post
Programmer: Shao Zheng
Email: shaoz@sina.com
Date:2000.09.23
Algorithm: Dynamic Programming, O(N^2)
}
Const
  InputFileName='POST.IN';
  OutputFileName='POST.OUT';
  MaxOfficeCount=30;
  MaxVillageCount=420;

Var
  Fi,Fo:Text;
  OfficeCount,VillageCount:integer;
  Position:array[1..MaxVillageCount]of integer;

Procedure Init;
var vc:integer;
begin
  assign(Fi,InputFileName);
  assign(Fo,OutputFileName);
  reset(Fi);
  read(Fi,VillageCount,OfficeCount);
  for vc:=1 to VillageCount do read(Fi,Position[vc]);
  close(fi);
end;

Function GetCost(left,right:integer):Longint;
var
  mean:integer;
  v:integer;
  result:longint;
begin
  mean:=Position[(left+right)div 2];
  result:=0;
  for v:=left to right do
    inc(result,abs(mean-Position[v]));
  GetCost:=result;
end;

Type
  TBackWay=array[1..MaxOfficeCount,1..MaxVillageCount]of integer;
Var
  Cost:array[1..MaxOfficeCount,1..MaxVillageCount]of longint;
  BackWay:^TBackWay;

Procedure Process;
var o,v,i:integer;
  temp:Longint;
begin
  for o:=1 to OfficeCount do
   for v:=1 to VillageCount do
    begin
      Cost[o,v]:=MaxLongint;
      BackWay^[o,v]:=-1;
    end;
  for v:=1 to VillageCount do Cost[1,v]:=GetCost(1,v);
  for o:=2 to OfficeCount do
   for v:=o to VillageCount do
    for i:=o-1 to v-1 do
     begin
       temp:=Cost[o-1,i]+GetCost(i+1,v);
       if temp<Cost[o,v] then
         begin Cost[o,v]:=temp;
               BackWay^[o,v]:=i;
         end;
     end;
end;

Procedure Print;
var officelist:array[1..MaxOfficeCount]of integer;
  v,o:integer;
begin
  rewrite(Fo);
  writeln(Fo,Cost[OfficeCount,VillageCount]);
  v:=VillageCount;
  for o:=OfficeCount downto 1 do
    begin
      if o=1 then officelist[o]:=(v+1)div 2 else
        officelist[o]:=(v+BackWay^[o,v]+1)div 2;
      v:=BackWay^[o,v];
    end;
  write(Fo,Position[officelist[1]]);
  for o:=2 to OfficeCount do
    write(Fo,' ',Position[officelist[o]]);
  writeln(fo);
  close(Fo);
end;

{Main Program}
BEGIN
  new(BackWay);
  Init;
  Process;
  Print;
END.
