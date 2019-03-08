var i,n,x,k,ans:longint;

begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);rewrite(output);
  read(n,x);
  ans:=0;
  for i:=1 to n do
  begin
    k:=i;
    while k>=10 do
    begin
      if k mod 10=x then inc(ans);
      k:=k div 10;
    end;
    if k=x then inc(ans);
  end;
  writeln(ans);
  close(input);close(output);
end.