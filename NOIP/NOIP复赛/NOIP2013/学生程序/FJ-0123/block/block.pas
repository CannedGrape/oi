var n,i,ans:longint;
    a:array[0..1000000]of longint;
begin
  assign(input,'block.in');
  assign(output,'block.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    if a[i]>a[i-1] then
      ans:=ans+a[i]-a[i-1];
  end;
  writeln(ans);
  close(input);
  close(output);
end.