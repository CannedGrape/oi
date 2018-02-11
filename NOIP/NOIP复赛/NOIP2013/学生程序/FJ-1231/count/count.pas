var i,s,n,m,num:longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  num:=0;
  s:=0;
  for i:=1 to n do
    begin
      s:=i;
      while s>0 do
        begin
          if (s mod 10)=m then inc(num);
          s:=s div 10;
        end;
    end;
  writeln(num);
close(input);
close(output);
end.



