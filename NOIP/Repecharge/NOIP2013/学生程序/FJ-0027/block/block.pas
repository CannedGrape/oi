var n,i:longint;
    a:array[0..100010]of int64;
    ans:int64;
begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    if a[i]-a[i-1]>0 then
    ans:=ans+a[i]-a[i-1];
  end;
  writeln(ans);
close(input);close(output);
end.