program count;
var
  n,x,i,j,s:longint;
  st,sx:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  s:=0;
  str(x,sx);
  for i:=1 to n do
  begin
    str(i,st);
    for j:=1 to length(st) do
    if st[j]=sx then inc(s);
  end;
  writeln(s);
  close(input);
  close(output);
end.