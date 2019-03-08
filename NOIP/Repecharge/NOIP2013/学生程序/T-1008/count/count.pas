var
  i,j,m,n,num,k,o:Longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,m);
  for i:=1 to n do
  begin
  k:=i;
  while k>0 do
  begin
    if k mod 10=m then
    begin
    inc(num);
    end;
    k:=k div 10;
    end;
  end;
  writeln(num);
  close(input);close(output);
end.
