var i,j,n,x:longint;
    total:qword;
    s,x2:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  read(n,x);
  str(x,x2);
  total:=0;
  for i:=1 to n do
  begin
    str(i,s);
    for j:=1 to length(s) do if s[j]=x2 then total:=total+1;
  end;
  write(total);
  close(input);
  close(output);
end.