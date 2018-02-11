program count;
var i,n,x,s,m:longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  for i:=1 to n do
  begin
    s:=i;
    repeat
      if s mod 10=x then inc(m);
      s:=s div 10;
    until s=0;
  end;
  write(m);
  close(input);
  close(output);
end.