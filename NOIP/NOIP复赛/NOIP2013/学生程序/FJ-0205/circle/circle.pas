var n,m,k,x:longint;
    mi:longint;
    num:array[0..1000] of longint;
procedure init;
begin
  readln(n,m,k,x);
end;
procedure change;
begin
  mi:=0;
  while k>0 do
  begin
    mi:=mi+1;
    num[mi]:=k mod 2;
    k:=k div 2;
  end;
end;
procedure qcalc;
var sum,t:int64;
    i:longint;
begin
  sum:=m; t:=10;
  for i:=1 to mi do
  begin
    if num[i]=1 then sum:=sum*t mod n;
    t:=t*t mod n;
  end;
  x:=(int64(x)+sum) mod n;
end;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  init;
  change;
  qcalc;
  writeln(x);
  close(input);
  close(output);
end.
