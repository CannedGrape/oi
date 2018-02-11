program count;
{Uses math;}
Var
  n,x,c,i:longint;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(n,x);
  for i:=1 to n do
    begin
      if (i mod 10=x) then c:=c+1;
      if ((i mod 100) div 10=x) then c:=c+1;
      if ((i mod 1000) div 100=x) then c:=c+1;
      if ((i mod 10000) div 1000=x) then c:=c+1;
      if ((i mod 100000) div 10000=x) then c:=c+1;
      if ((i mod 1000000) div 100000=x) then c:=c+1;
    end;
  writeln(c);
  close(input);
  close(output);
end.
