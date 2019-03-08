var n,i,ans:longint;
    a,b:array[1..100000] of longint;

begin
  assign(input,'match.in');
  assign(output,'match.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  readln;
  for i:=1 to n do read(b[i]);
  readln;
  ans:=0;
  for i:=1 to n do
    if a[i]<>b[i] then inc(ans);
  writeln(ans-1);
  close(input);
  close(output);
end.