program count;
var
  x,n,j,f:int64;
  i:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,x);
  f:=0;
  for i:=1 to n do
  begin
    j:=i;
    repeat
    begin
      if j mod 10=x then inc(f);
      j:=j div 10;
    end;
    until j=0;
  end;
  writeln(f);
  close(input);close(output);
end.

