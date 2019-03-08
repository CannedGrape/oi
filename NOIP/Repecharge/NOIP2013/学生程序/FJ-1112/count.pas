var n,x,w,j,i,ans:longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  for i:=1 to n do
  begin
    w:=i;
    while w<>0 do
      begin
        j:=w mod 10;
        if j=x then inc(ans);
        w:=w div 10;
      end;
  end;
  writeln(ans);
  close(input);
  close(output); 
end.
