program match;
var i,n,ans:longint;
  a,b,c,d:array[1..10000000]of longint;
procedure qsorta(k,m:longint);
var s,t,mid,h:longint;
begin
 s:=k;t:=m;
  mid:=a[(s+t)div 2];
  while s<t do
 begin
  while a[s]<mid do
     inc(s);
   while a[t]>mid do
     dec(t);
   if s<=t then
     begin
       h:=a[s];
       a[s]:=a[t];
       a[t]:=h;
     inc(s);
     dec(t);
     end;
  if t>k then
    qsorta(k,s);
  if s<m then
    qsorta(s,m);
 end;
end;
procedure qsortb(k,m:longint);
var s,t,mid,h:longint;

begin
 s:=k;t:=m;
  mid:=b[(s+t)div 2];
  while s<t do
 begin
  while b[s]<mid do
     inc(s);
   while b[t]>mid do
     dec(t);
   if s<=t then
     begin
       h:=b[s];
       b[s]:=b[t];
       b[t]:=h;
     inc(s);
     dec(t);
     end;
  if t>k then
    qsortb(k,s);
  if s<m then
    qsortb(s,m);
 end;
end;
begin
 assign(input,'match.in');
 assign(output,'match.out');
 reset(input);
 rewrite(output);
  readln(n);
  for i:=1 to n do
 begin
   read(a[i]);
   read(b[i]);
 end;
  for i:=1 to n do
   begin
    c[i]:=a[i];
    d[i]:=b[i];
   end;
 qsorta(1,n);
 qsortb(1,n);
 for i:=1 to n do
  begin
   if a[i]-b[i]<>c[i]-d[i] then
   ans:=(ans+1)mod 99999997;
  end;
 writeln(ans div 2);
 close(input);
 close(output);
end.



