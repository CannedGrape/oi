var n,i,j:longint;
    ans:int64;
    h:array[0..110000]of longint;
function max(a,b:int64):int64;
begin
  if a>b then exit(a) else exit(b);
end;
begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  for i:=1 to n do ans:=ans+max(0,h[i]-h[i-1]);
  writeln(ans);
close(input);close(output);
end.