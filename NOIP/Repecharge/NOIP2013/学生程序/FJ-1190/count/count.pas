var
  n,k,i,t,y:longint;
  s:longint;
begin
assign(input,'count.in');
reset(input);
  readln(n,k);
close(input);
  for i:=1 to n do
    begin
      t:=i;
      while t>0 do
        begin
          y:=t mod 10;
          t:=t div 10;
          if y=k then inc(s);
        end;
    end;
assign(output,'count.out');
rewrite(output);
  writeln(s);
close(output);
end.