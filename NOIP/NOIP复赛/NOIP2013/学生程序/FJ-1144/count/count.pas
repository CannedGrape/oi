var
  s,y,i,x,j,n,m:longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  for i:=1 to n do
  begin
    y:=i;
    while y<>0 do
    begin
      if (y mod 10=x) then inc(s);
      y:=y div 10;
    end;
  end;
  writeln(s);
  close(input);
  close(output);
end.
