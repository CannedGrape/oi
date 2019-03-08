program count;
  var
    n,x,i,s:integer;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  read(n);read(x);
  for i:=1 to 99 do
    begin
      if(i div 10=x) or (i mod 10=x)then
      s:=s+1;
    end;
    write(s);
    close(input);
    close(output);
end.


