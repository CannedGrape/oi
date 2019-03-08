program count;
var
  i,j,n,x,ans:longint;
  a,b:string;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(n,x);
  str(x,a);   ans:=0;
  for i:=1 to n do
  begin
    str(i,b);
    for j:=1 to length(b) do
    begin
      if b[j]=a then
      begin
        inc(ans);
      end;
    end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.