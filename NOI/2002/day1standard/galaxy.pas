{ NOI 2002 Day 1 Problem 1 Galaxy.pas   by Rujia Liu}
const
  maxn=30000;
var
  Father,Count,Behind:array[1..maxn] of integer;

function Find_Father(x:integer):integer;
var i,j,f,next:integer;
begin
  {find Father}
  i:=x; while Father[i]<>i do i:=Father[i]; f:=i;
  {path compress}
  i:=x;
  while i<>f do
  begin
    next:=Father[i];
    Father[i]:=f;
    {calculate Behind}
    j:=next;
    repeat
      Behind[i]:=Behind[i]+Behind[j];
      j:=Father[j];
    until Father[j]=j;
    i:=next;
  end;
  find_Father:=f;
end;

procedure MoveShip(x,y:integer);
var fx,fy:integer;
begin
  fx:=find_Father(x);
  fy:=find_Father(y);
  Father[Father[fx]]:=fy;
  Behind[fx]:=Behind[fx]+Count[fy];
  Count[fy]:=Count[fy]+Count[fx];
end;

procedure CheckShip(x,y:integer);
var f1,f2:integer;
begin
  f1:=Find_Father(x);
  f2:=Find_Father(y);
  if f1<>f2 then writeln(-1) else writeln(abs(Behind[x]-Behind[y])-1);
end;

var x,y:integer;
    i,CmdCount:longint;
    ch:char;
begin
  {init}
  assign(input,'galaxy.in');
  reset(input);
  for i:=1 to maxn do
  begin
    Father[i]:=i;
    Count[i]:=1;
    Behind[i]:=0;
  end;
  readln(CmdCount);

  {process}
  assign(output,'galaxy.out');
  rewrite(output);
  for i:=1 to CmdCount do
  begin
    read(ch);
    case ch of
      'M' : begin readln(x,y); MoveShip(x,y); end;
      'C' : begin readln(x,y); CheckShip(x,y); end;
    end;
  end;
  close(input);
  close(output);
end.