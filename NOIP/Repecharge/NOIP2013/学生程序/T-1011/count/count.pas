var n,x,i,q,t:longint; ans:int64;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,x);
  for i:=1 to n do
  begin
    t:=i;
    while t>0 do
    begin
      q:=t mod 10;
      if q=x then inc(ans);
      t:=t div 10;
    end;
  end;
  writeln(ans);
  close(input);close(output);
end.