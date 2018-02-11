var a,b,c,e,i,j,k:longint;
    x,y:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  read(a,b);
  str(b,y);
  for i:=1 to a do
  begin
    str(i,x);
    for j:=1 to length(x) do
    begin
      if (x[j]=y) then inc(k);
    end;
  end;
  writeln(k);
  close(input);
  close(output);
end.