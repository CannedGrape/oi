var
  n,x,i,j,s,t,k:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,x);
  if (n<10) and (n=x) then begin writeln(1); close(input);close(output); halt; end;
  if (n<10) and (n<>x) then begin writeln(0); close(input);close(output); halt; end;
  for i:=n downto 1 do
  begin
  k:=i;
  while k<>0 do
  begin
  s:=k mod 10; if x=s then inc(t);
  k:=k div 10;
  end;
  end;
  writeln(t);
  close(input);close(output);
end.
