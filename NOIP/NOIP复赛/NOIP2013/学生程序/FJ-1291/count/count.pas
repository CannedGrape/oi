program count;
var
  n,i,j,s,x:longint;
  y,a:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  str(x,y);
  s:=0;
  for i:=1 to n do
  begin
    str(i,a);
    for j:=1 to length(a) do
      if a[j]=y then inc(s);
  end;
  write(s);
  close(input);
  close(output);
end.