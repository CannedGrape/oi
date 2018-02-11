var
  n,m,k,x,i,now:longint;
  s:int64;
begin
assign(input,'circle.in'); reset(input);
assign(output,'circle.out'); rewrite(output);
  readln(n,m,k,x);
  s:=1;
  for i:=1 to k do
    s:=10*s;
  now:=x+1;
  for i:=1 to s do
  begin
    now:=now+m;
    if now>n then now:=now mod n;
  end;
  write(now-1);
close(input); close(output);
end.
