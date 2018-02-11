var n,x,i,s:longint;
procedure fenjie(a:longint);
var t:longint;
begin
  repeat
  t:=a mod 10;
  if t=x then s:=s+1;
  a:=a div 10;
  until a=0;
end;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,x);
  for i:=1 to n do
  begin
    fenjie(i);
  end;
  writeln(s);
  close(input);close(output);
end.
