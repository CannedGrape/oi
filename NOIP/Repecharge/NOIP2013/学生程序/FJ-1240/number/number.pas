program number;
var shu,fenshu,tezheng:array[1..1000000] of longint;
    i,n,p,max:longint;
function maxx(a,b:longint):longint;
begin
  if a>=b then exit(a)
  else exit(b);
end;
procedure tezhengx(x:longint);
var i:longint;
    f:array[1..1000000] of longint;
begin
  f[1]:=shu[1];
  for i:=2 to x do f[i]:=maxx(f[i-1]+shu[i],f[i-1]);
  tezheng[x]:=f[x];
end;
function fenshux(x:longint):longint;
var i,max:longint;
begin
  max:=-maxlongint;
  for i:=1 to x do
    if fenshu[i]+tezheng[i]>max then max:=fenshu[i]+tezheng[i];
  fenshux:=max;
end;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  read(n,p);
  for i:=1 to n do read(shu[i]);
  tezheng[1]:=shu[1];
  for i:=2 to n do tezhengx(i);
  fenshu[1]:=shu[1];
  for i:=2 to n do fenshu[i]:=fenshux(i-1);
  max:=-maxlongint;
  for i:=1 to n do if fenshu[i]>max then max:=fenshu[i];
  write(max mod p);
  close(input);
  close(output);
end.
