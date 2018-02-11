var shu,te,fen:array[1..1000000] of longint;
    n,p,a,b,c,int,max:longint;
function doing(i,j:longint):longint;
var d,ass:longint;
begin
  ass:=0;
  for d:=i to j do
    ass:=ass+shu[d];
  doing:=ass;
end;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,p);
  for a:=1 to n do
    read(shu[a]);
  te[1]:=shu[1];
  for a:=2 to n do
  begin
    max:=-maxlongint;
    for b:=1 to a do
    begin
      int:=doing(b,a);
      if int>max then max:=int;
    end;
    te[a]:=max;
  end;
  fen[1]:=te[1];
  max:=fen[1];
  for a:=2 to n do
  begin
    if fen[a-1]+te[a-1]>max then max:=fen[a-1]+te[a-1];
    fen[a]:=max;
  end;
  writeln(max mod p);
  close(input);
  close(output);
end.