var h:array[0..110000] of int64;
i,n:longint;
ans:int64;

begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  h[0]:=0;  ans:=0;
  for i:=1 to n do
  if h[i]>h[i-1] then inc(ans,h[i]-h[i-1]);
  writeln(ans);
  close(input); close(output);
end.
