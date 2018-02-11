program match(input,output);
var
n,i,j,mins:longint;
a,b:array[1..100000] of int64;
min:int64;

procedure jh(var a,b:int64);
var
t:int64;
begin
  t:=a;
  a:=b;
  b:=t;
end;

function pf(a:int64):int64;
begin
  pf:=a*a;
end;

function try(p:longint):boolean;
var
i,j:longint;
min1:int64;
begin
  min1:=0;
  jh(a[p],a[p+1]);
  for i:=1 to n do
    min1:=min1+pf(abs(a[i]-b[i]));
  if min1<min then begin jh(a[p],a[p+1]); try:=true; end
  else begin jh(a[p],a[p+1]); try:=false; end;
end;

begin
  assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);
  mins:=0;
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  for i:=1 to n do
    min:=min+pf(abs(a[i]-b[i]));
  for i:=1 to n-1 do
    if try(i) then
      begin
        mins:=mins+1;
        jh(a[i],a[i+1]);
      end;
  if mins>99999997 then mins:=mins mod 99999997;
  writeln(mins);
  close(input);
  close(output);
end.



