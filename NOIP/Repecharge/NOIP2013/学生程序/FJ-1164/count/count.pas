Program count;
var
  n,sum:longint;
  x:integer;
begin
  assign(input,'count.in');  reset(input);
  assign(output,'count.out');  rewrite(output);
  readln(n,x);
  if x=0 then sum:=n div 10;writeln(sum);exit;
  sum:=n div 10;
  if (n mod 10)>=x then sum:=sum+1;
  if ((n div 10)-1)>x then sum:=sum+9;
  if ((n div 10)-1)=x then sum:=sum+(n mod 10);
  writeln(sum);
  close(input);close(output);
end.
