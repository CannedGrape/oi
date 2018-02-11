var
  tot,n,i,j,x,k,a:longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);tot:=0;
  for i:=1 to n do
    begin
      k:=i;
      while k>0 do
        begin
          a:=k mod 10;
          if a=x then inc(tot);
          k:=k div 10;
        end;
    end;
  writeln(tot);
  close(input);
  close(output);
end.
