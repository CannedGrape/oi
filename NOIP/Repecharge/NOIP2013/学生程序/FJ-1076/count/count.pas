program exp3;
var s,x,y,i,j:longint;
begin
  assign(input,'count.in');
  reset(input);
  read(x,y);
  s:=0;
  for i:=1 to x do
  begin
    j:=i;
    if i>9 then
    begin
      while j div 10<>0 do
      begin
        j:=j mod 10;
        if j=y then inc(s);
      end;
      if i div 10=y then inc(s);
      end
    else
      if j=y then inc(s);
   end;
   assign(output,'count.out');
   rewrite(output);
    write(s);
    close(input);
    close(output);
end.