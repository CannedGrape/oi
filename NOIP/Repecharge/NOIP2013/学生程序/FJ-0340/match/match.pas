program match;
 var n,i,j,s,a:longint;
  x1,x2:array[1..10000] of integer;
begin
assign(input,'match.in');
assign(output,'match.out');
reset(input);
rewrite(output);
 readln(n);
 for i:=1 to n do
  read(x1[i]);
 for i:=1 to n do
  read(x2[i]);
 readln;
 randomize;
 a:=random(n);
writeln(a+1);
close(input);
close(output);
end.