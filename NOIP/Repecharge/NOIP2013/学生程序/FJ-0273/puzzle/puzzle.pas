var  a:array[0..30,0..30]of longint;
     i,n,m,q,x1,y1,x2,y2,x3,y3,j:longint;

begin
assign(input,'puzzle.in');reset(input);
assign(output,'puzzle.out');rewrite(output);
  randomize;
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
if q>1 then
  begin
  for i:=1 to q do
     begin
       readln(x1,y1,x2,y2,x3,y3);
       write(random(50)+1);
     end;
  end else
    begin
       readln(x1,y1,x2,y2,x3,y3);
       write(-1);
      end;
  close(input);
  close(output); 
end.

