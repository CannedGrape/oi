var n,l,j:qword;k:longint;
x:integer;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(n,x);
  l:=0;
  for k:=1 to n do
    begin
      j:=k;
      while j>0 do
        begin
          if j mod 10=x then
            begin
              j:=j div 10;
              inc(l);
            end
          else
            j:=j div 10;
        end;
    end;
  writeln(l);
  close(input);
  close(output);
end.
