var a:array [0..100001] of longint;
    i,n,ans:longint;
begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);

  readln(n);
  for i:=1 to n do read(a[i]);
  ans:=a[1];
  for i:=2 to n do
    if a[i]>a[i-1] then ans:=ans+a[i]-a[i-1];
  writeln(ans);

close(input);
close(output);
end.
