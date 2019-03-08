var n,i:longint;
    f,h:array[1..100000] of int64;

begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  fillchar(f,sizeof(f),0);
  f[1]:=h[1];
  for i:=2 to n do
   if h[i]<=h[i-1] then f[i]:=f[i-1]
   else f[i]:=f[i-1]+h[i]-h[i-1];
  writeln(f[n]);
  close(input);close(output);
end.

