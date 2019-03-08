var
  n,i,j,m:longint;
  total:int64;
  s1,s:string;
procedure doing(s2:string);
var
  j:integer;
begin
  for j:=1 to length(s2) do
    if s2[j]=s1 then
      total:=total+1;
end;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  total:=0;
  read(n);
  read(m);
  str(m,s1);
  for i:=1 to n do
    begin
      str(i,s);
      doing(s);
    end;
  write(total);
  close(input);
  close(output);
end.
