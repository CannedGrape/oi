(*

                        NOI 2002 Day 2 Problem 2

                                 Tetris

                           Problem   by Rujia Liu
                        Souce Code   by Rujia Liu
*)

{$M 65520,0,655360}
{$I COMMON.PAS}
{$I SOLVEIT.PAS}
const
  infile='tetris.in';
  outfile='tetris.out';

procedure ReadStatus;
var i,k:longint;
begin
  assign(f,infile);
  reset(f);
  readln(f,Column);
  for i:=1 to Column do read(f,Num[i]);
  close(f);
end;

{ Make Every Column 0-3 }
procedure prep;
var i,Min:integer;
    Ok:boolean;
begin
  Cmd:=0;
  assign(f,outfile);
  rewrite(f);
  while true do
  begin
    ok:=true;
    Min:=maxint;
    for i:=1 to Column do
      if Num[i]<Min then min:=Num[i];
    for i:=1 to Column do
      if Num[i]>Min+3 then Ok:=false;
    if Ok then break;
    for i:=1 to Column do
      if Num[i]=Min then
        WriteCommand(1,i);
  end;
end;

{ Make it flat! }
procedure Flatten;
var
  i,j,Max:integer;
begin
  Max:=0;
  for i:=1 to Column do
    if Num[i]>Max then Max:=Num[i];
  j:=Column mod 4;
  if j=0 then j:=4;
  { Make Last Column the Highest }
  while Num[Column]<Max do
    for i:=1 to j do
      WriteCommand(1,Column+1-i);
  Max:=Num[Column];
  { Use Type 2 from left to right }
  for i:=1 to (Column-1) div 4 do
    for j:=1 to Max-Num[(i-1)*4+1] do
      WriteCommand(2,(i-1)*4+1);
end;

procedure Solve;
var i:longint;
    ok:boolean;
begin
  Prep;
  { From Left to Right , Consider 5 Columns, but only check 4 }
  for i:=1 to (Column-1) div 4 do
    SolveIt(5,4,(i-1)*4+1);
  { Last lines }
  case Column mod 4 of
    2: Solve2(Column-1);
    3: SolveIt(3,3,Column-2);
    0: SolveIt(4,4,Column-3);
  end;
  Flatten;
  close(f);
end;

begin
  ReadStatus;
  Solve;
end.