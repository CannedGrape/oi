program count;
var
  i,j,k,m,n,s,t:longint;
  a:char;
  b:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  a:=chr(m+48);
  for i:=1 to n do
  begin
    str(i,b);
    for j:=1 to length(b) do
      if b[j]=a then t:=t+1;
  end;
  writeln(t);
  close(input);
  close(output);
end.