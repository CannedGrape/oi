var n,x,a,b:longint;
    max:qword;
    s,m:string;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(n,x);
  str(x,m);
  max:=0;
  for a:=1 to n do
  begin
    str(a,s);
    for b:=1 to length(s) do
	  if s[b]=m then inc(max);
  end;
  writeln(max);
  close(input);
  close(output);
end.