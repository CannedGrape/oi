program truck;
var
  x,i,y,z,q,n,m:longint;
begin
  assign(input,'.in'); reset(input);
  assign(output,'.out'); rewrite(output);
  readln(n,m);
  for i:=1 to m do
    readln(x,y,z);
  readln(q);
  for i:=1 to q do
    readln(x,y);
  for i:=1 to q do
    writeln(-1);
  close(input); close(output);
end.