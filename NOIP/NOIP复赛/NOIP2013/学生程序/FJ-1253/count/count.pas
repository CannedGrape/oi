var i,j,n,x,num:longint;
    s:ansistring;
    y:string;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(n,x);
  str(x,y);
  for i:=1 to n do
  begin
    str(i,s);
    for j:=1 to length(s) do
      if s[j]=y then inc(num);
  end;
  writeln(num);
  close(input);
  close(output);
end.
