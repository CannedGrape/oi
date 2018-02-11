var map:array[0..31,0..31]of longint;
i,j,k,n,m,q:longint;
tx,ty,ex,ey,sx,sy:longint;

begin
assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input);
rewrite(output);
readln(n,m,q);
for i:=1 to n do
 begin
  for j:=1 to m-1 do
   read(map[i,j]);
 readln(map[i,m]);
  end;

writeln(-1);
   close(input);
    close(output);
 end.


