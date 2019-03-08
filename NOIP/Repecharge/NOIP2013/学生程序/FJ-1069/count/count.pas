program count;
var
  n,i,j,x:integer;
  c:char;
  s:string;
  total:qword;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  c:=chr(x+48);
  total:=0;
  for i:=1 to n do
  begin
    str(i,s);
    for j:=1 to length(s) do
      if (s[j]=c)then inc(total);
  end;
  writeln(total);
  close(input);
  close(output);
end.
