var
  n,i,j,ios,b,g,x:longint;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  read(n);
  readln(x);
  for i:=1 to n do
  begin
    b:=i;
    while b>0 do
    begin
      g:=b mod 10;
      if g=x then ios:=ios+1;
      b:=b div 10;
    end;
  end;
  writeln(ios);
  close(input);
  close(output);
end.
