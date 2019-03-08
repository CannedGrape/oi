program count;
var n,i,m,j:longint;
    x:integer;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input) ;
  rewrite(output);
  readln(n,x);
  m:=0;
  j:=i;
  for i:=1 to n do
  repeat
    if i mod 10=x then
    begin
      inc(m,2);
      j:=j div 10;
    end;
  until j=0;
  write(m);
  close(input); close(output);
end.
