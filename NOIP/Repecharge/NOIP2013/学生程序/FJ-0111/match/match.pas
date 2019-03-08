var
  a:array[1..2,1..100000]of longint;
  n,i,j,k,t:longint;
begin;
  assign(input,'match.in'); reset(input);
  assign(output,'match.out'); rewrite(output);
  readln(n);
  for i:=1 to 2 do
    for j:=1 to n do
      read(a[i,j]);
   for i:=1 to n do
     if a[1,i]=a[2,i+1] then
     begin
       k:=a[1,i]; a[1,i]:=a[1,i+1];a[1,i+1]:=k;
       inc(t);
     end;
  writeln(t);
 close(input);close(output);
end.