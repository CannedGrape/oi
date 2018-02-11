program p1;
var n,i:longint;
    ans:int64;
    a:array[0..100010]of int64;
function max(a,b:int64):int64;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    ans:=ans+max(a[i]-a[i-1],0);
  end;
  writeln(ans);
  close(input);close(output);
end.