program truck;
var i,j:longint;
a,b:array[1..10000,1..10000]of longint;
function max(s,t:longint);
begin
  if s>t then exit(s) else exit(t);
end;
function min(s,t:longint);
begin
  if s<t then exit(s) else exit(t);
end;
begin
  assign(input,
  readln(n,m);
  for i:= 1 to m do
  readln(e,f,g);
  readln(q);
  for i:=1 to q do
   readln(x,y);
  b[x,y]:=max((max(a[x,y],a[y,x]),min(a[x,y],a[x+1,y+1]
  writeln(b[x,y]);


end;

