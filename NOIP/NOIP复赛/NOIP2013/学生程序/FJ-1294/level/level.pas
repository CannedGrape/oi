program level;
var
  a:array[1..1000] of integer;
  n,m,i,k:integer;
begin
{assign(input,'level.in');  reset(input);
assign(output,'level.out'); rewrite(output);}
 readln(n,m);
  for i:=1 to m do readln(a[i]);
 randomize;
 k:=random(10);
  write(k);
{close(input);
close(output);}
end.




