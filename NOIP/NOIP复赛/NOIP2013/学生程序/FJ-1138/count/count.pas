var
  n,x,ans,s,i:longint;
  a:array[0..1000001]of integer;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  for i:=1 to n do
    begin
      s:=i;
      while s<>0 do
        begin
          if (s mod 10)=x then inc(ans);
          s:=s div 10;
        end;
    end;
  writeln(ans);
  close(input);
  close(output);
end.
