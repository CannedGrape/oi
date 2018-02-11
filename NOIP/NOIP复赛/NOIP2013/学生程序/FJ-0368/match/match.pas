program match;
var n,i,j,d,bs:longint;
min:qword;
a,b:array[1..10000]of longint;
procedure swap(a,b:longint);
var t:longint;
begin
 t:=a;a:=b;b:=t;
end;
procedure try(l,r:longint);
var t,i,k,j:longint;
s:qword;
begin
s:=0;
  i:=l;j:=r;
  while a[i]=b[i] do inc(i);
  while a[j]=b[j] do dec(j);
  for k:=i to j do
    s:=s+sqr(a[k]-b[k]);
  if s<min then begin min:=s;bs:=d; end;
   for t:=i to j do
     if (sqr(b[t]-a[t])+sqr(b[t+1]-a[t+1]))>(sqr(b[t+1]-a[t])+sqr(b[t]-a[t+1])) then
     begin
      swap(b[t],b[t+1]);swap(a[t],a[t+1]);inc(d);
      try(t+1,j);
     end;
end;
begin
assign(input,'match.in');
reset(input);
assign(output,'match.out');
rewrite(output);
  readln(n);min:=99999999999999;
   for i:=1 to n do
    read(a[i]);
   for i:=1 to n do
    read(b[i]);
   try(1,n);
   bs:=bs mod 99999997;
   writeln(bs);
close(input);close(output);
end.
