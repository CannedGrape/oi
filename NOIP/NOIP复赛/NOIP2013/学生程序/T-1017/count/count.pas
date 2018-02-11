var
  a,b,j,i,ans:longint;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count,out');
  rewrite(output);
  readln(a,b);
  for i:=1 to a do begin
  j:=i;
  while j>0 do begin
  if j mod 10=b then inc(ans);
  j:=j div 10;
  end;
  end;
  writeln(ans);
  close(input);close(output);
end.
