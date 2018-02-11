var n,x,i,j:longint;
    t,max:int64;
    a:array[1..1000000] of longint;
    f:array[1..1000000] of longint;

function modd (a,b:longint):longint;
var k:boolean;
    c:longint;
begin
  if a<0 then k:=true else
  k:=false;
  c:=abs(a) mod b;
  if k then
   exit(-1*c);
  exit(c);
end;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);rewrite(output);
  read(n,x);
  //for i:=1 to n do f[i]:=-maxlongint;
  for i:=1 to n do read(a[i]);
  f[1]:=a[1];
  for i:=2 to n do
  begin
   max:=-maxlongint;t:=0;
   for j:=1 to i-1 do
   begin
    t:=t+a[j];
    if t>max then max:=t;
    if t<0 then t:=0;
   end;
   f[i]:=modd(t+a[i],x);
  end;
  {for i:=1 to n do
   write(f[i],' ');
   writeln;}
  a[1]:=f[1];
  for i:=2 to n do
  begin
  max:=-maxlongint;
  for j:=1 to i-1 do
   if f[j]+a[j]>max then max:=f[j]+a[j];
  a[i]:=max;
  end;
  {for i:=1 to n do
   write(a[i],' ');
   writeln; }
  max:=-maxlongint;
  for i:=1 to n do
   if a[i]>max then max:=a[i];
  writeln(modd(max,x));
  close(input);close(output);
end.