var
  n,p:longint;
  a:array[1..1000000] of longint;
  b,c:array[0..1000000] of int64;
  i,j:longint;
  maxs:int64;
  ans:int64;
function max(a,b:int64):int64;
begin
  if a>b then exit(a) else exit(b);
end;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  b[0]:=-maxlongint div 2;
  maxs:=-maxlongint;
  for i:=1 to n do
    b[i]:=max(b[i-1]+a[i],a[i]);
  maxs:=b[1];
  for i:=2 to n do
    if b[i]>maxs then maxs:=b[i] else b[i]:=maxs;
  c[1]:=b[1] mod p;
  ans:=c[1];
  maxs:=c[1]+b[1];
  for i:=2 to n do
    begin
    if b[i-1]+c[i-1]>maxs then begin maxs:=b[i-1]+c[i-1]; ans:=maxs; end;
    c[i]:=maxs;
    end;
  writeln(ans mod p);
  close(input);
  close(output);
end.
