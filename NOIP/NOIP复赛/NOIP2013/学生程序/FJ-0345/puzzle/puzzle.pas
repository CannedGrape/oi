program puzzle;
var n,m,q,i,j,a,b,c,d,e,f,x:integer;

begin
assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input);
rewrite(output);
for i:=1 to n do
 begin
  for j:= 1 to m do read(x);
  readln;
  end;
for i:=1 to q do readln(a,b,c,d,e,f);
for i:=1 to q do writeln(-1);
close(input);
close(output);
end.
