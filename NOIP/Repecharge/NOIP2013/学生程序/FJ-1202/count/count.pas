var
n,m,i,s,i1:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,m);s:=0;
  for i:=1 to n do
  begin
    i1:=i;
    while i1<>0 do
    begin
      if i1 mod 10 =m then inc(s);
      i1:=i1 div 10;
      end;
    end;
  writeln(s);
  close(input);
  close(output);
end.
