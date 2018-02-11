{ COMMON.PAS for TETRIS  by Rujia Liu}
const
  MaxC=1500;
  Check:Array[1..19] of string[4]=(
  '0','0000','00','100','001',
  '10','01','000','101','10',
  '01','011','110','000','000',
  '02','20','00','00');
  Add:Array[1..19] of string[4]=(
  '4','1111','22','121','121',
  '22','22','121','121','13',
  '31','211','112','211','112',
  '31','13','31','13');
var
  Column,Cmd:longint;
  Num:array[1..MaxC] of longint;
  f:text;

procedure TryPutIt(t,c,flag:integer);
var i:integer;
begin
  for i:=1 to length(check[t]) do
    Num[c-1+i]:=Num[c-1+i]+(ord(Add[t,i])-ord('0'))*flag;
end;

procedure WriteCommand(t,c:integer);
var i:integer;
begin
  for i:=1 to length(check[t]) do
    Num[c-1+i]:=Num[c-1+i]+(ord(Add[t,i])-ord('0'));
  writeln(f,t,' ',c);
  inc(Cmd);
end;
