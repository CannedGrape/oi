program match;
var
 a,b:array[1..100000] of longint;
 n,i,q,p:longint;
begin
 assign(input,'match.in');reset(input);
 assign(output,'match.out');rewrite(output);
 readln(n);
 for i:=1 to n do
 read(a[i]);
 for i:=1 to n do
 read(b[i]);
  for i:=1 to n do
 if (a[i]<a[i+1]) and (a[i]<>b[i]) then
 begin p:=a[i]; a[i]:=a[i+1]; a[i+1]:=p; inc(q); end;
  for i:=1 to n do
 if (b[i]<b[i+1]) and (b[i]<>a[i]) then
 begin p:=b[i]; b[i]:=b[i+1]; b[i+1]:=p; inc(q); end;
 writeln(q mod 99999997);
 close(input);close(output);
 end.
