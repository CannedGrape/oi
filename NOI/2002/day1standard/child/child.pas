(*
                       NOI 2002 Day 1 Problem 2
                                Child
                           Sample Solution
                             by Rujia Liu
*)
uses
  childlib;
const
  MaxN=501;
var
  N,M,C,Tot:integer;
  Next:array[1..MaxN] of integer;
  ChildType:Array[1..MaxN] of integer;
  Possible:array[1..MaxN] of boolean;
  NTried:Array[1..MaxN] of integer;
  Tried:Array[1..MaxN,1..5] of integer;

{This is a Time-Space Trade off. This uses less memory but a lot of time}
function CalcChildType(Ref:integer):boolean;
var a,b:integer;
begin
  CalcChildType:=true;
  a:=Ref;
  ChildType[Ref]:=0;
  while a mod C+1<>Ref do
  begin
    b:=a mod C+1;
    if ChildType[a]=0 then ChildType[b]:=1-Next[a]
    else ChildType[b]:=Next[a];
    a:=b;
  end;
  if (ChildType[a]=0)and(Next[a]=1) then CalcChildType:=false;
  if (ChildType[a]=1)and(Next[a]=0) then CalcChildType:=false;
  ChildType[Ref]:=2;
end;

procedure PreProcess;
var i,j,Num1,Num2:integer;
begin
  GetNM(N,M);
  C:=N+M+1;
  for i:=1 to C do
    Next[i]:=Ask(i,i mod C+1,0);
  Tot:=0;
  for i:=1 to C do
  begin
    if not CalcChildType(i) then continue;
    Num1:=0; Num2:=0;
    for j:=1 to C do
    begin
      if ChildType[j]=0 then inc(Num1);
      if ChildType[j]=1 then inc(Num2);
    end;
    if (Num1=N) and (Num2=M) then
    begin
      Possible[i]:=True;
      inc(Tot);
    end
    else Possible[i]:=False;
  end;
end;

procedure Sieve;
var i,j,k,t,Turn:integer;
    ok:boolean;
    Result:integer;
begin
  for i:=1 to C do
  begin
    NTried[i]:=2;
    Tried[i,1]:=i;
    Tried[i,2]:=i mod C+1;
  end;

  for Turn:=1 to 5 do
    for i:=1 to C do
    begin
      if Tot=1 then
        for k:=1 to C do
          if Possible[k] then
          begin
            CalcChildType(k);
            for t:=1 to C do
              Answer(ChildType[t]);
          end;
      {Find a person to Ask about}
      for j:=1 to C do
      begin
        ok:=true;
        for k:=1 to NTried[i] do
          if j=Tried[i,k] then ok:=false;
        if ok then break;
      end;
      {Test Every Possibility}
      Result:=Ask(i,j,0);
      for k:=1 to C do
        if Possible[k] then
        begin
          CalcChildType(k);
          if (ChildType[i]=0)or((ChildType[i]=2)and(NTried[i] mod 2=1)) then {Say Truth}
          begin
            if (Result=0)and(ChildType[j]=0) then Possible[k]:=false;
            if (Result=1)and(ChildType[j]<>0) then Possible[k]:=false;
          end;
          if (ChildType[i]=1)or((ChildType[i]=2)and(NTried[i] mod 2=0)) then
          begin
            if (Result=0)and(ChildType[j]<>0) then Possible[k]:=false;
            if (Result=1)and(ChildType[j]=0) then Possible[k]:=false;
          end;
          if not Possible[k] then dec(Tot);
        end;
      inc(NTried[i]);
      Tried[i,NTried[i]]:=j;
    end;
end;

begin
  PreProcess;
  Sieve;
end.