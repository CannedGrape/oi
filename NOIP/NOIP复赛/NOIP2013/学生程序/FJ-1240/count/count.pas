program count;
var i,j,a,x,n,ans:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  read(n,x);
  for i:=1 to n do
  begin
    j:=i;
    if j>=10 then
    repeat
      a:=j div 10;
      j:=j mod 10;
      if a=x then inc(ans);
    until j<10;
    if j=x then inc(ans);
  end;
  write(ans);
  close(input);
  close(output);
end.