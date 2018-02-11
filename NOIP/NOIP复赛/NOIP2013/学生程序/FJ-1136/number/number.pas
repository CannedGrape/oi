program number;
var
  ans:int64;
  i,j,k,n,p:longint;
  a,f,maxn,d:array[0..1000007] of longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
   read(a[i]);
  for i:=1 to n do f[i]:=a[i];
  d[1]:=a[1];
  for i:=2 to n do
    begin
      f[i]:=max(f[i-1]+a[i],a[i]);
      d[i]:=max(d[i-1],f[i]);
    end;
  for i:=2 to n do maxn[i]:=-10000000;
  maxn[1]:=d[1];
  for i:=2 to n do
   begin
     for j:=1 to i-1 do
      if maxn[i]<d[j]+maxn[j] then
       maxn[i]:=d[j]+maxn[j];
   end;
  ans:=-10000000;
  for i:=1 to n do
   if maxn[i]>ans then ans:=maxn[i];
  writeln(ans mod p);
  close(input);
  close(output);
end.