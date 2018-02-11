program s1;
var
  n,i,j:longint;
  s:string;
  t:int64;
  x:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  read(n);
  read(x);
  delete(x,1,1);
  for i:=1 to n do
    begin
     str(i,s);
     for j:=1 to length(s) do
       if s[j]=x then inc(t)
    end;
  writeln(t);
  close(input);
  close(output);
end.
