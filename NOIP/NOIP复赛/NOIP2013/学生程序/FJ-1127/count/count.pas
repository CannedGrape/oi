var
  n,x,i,ans,k:longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  for i:=1 to n do begin
    k:=i;
  repeat
    if k mod 10=x then inc(ans);
    k:=k div 10;
  until k=0;
  end;
  writeln(ans);
  close(input);
  close(output);
end.
