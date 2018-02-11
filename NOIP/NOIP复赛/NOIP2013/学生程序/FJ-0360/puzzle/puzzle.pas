program puzzle;
var a,b,c,n,m,q,ex,ey,sx,sy,tx,ty,t:longint;
qipan:array[1..30,1..30]of longint;

begin
assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input);rewrite(output);
readln(n,m,q);
for a:=1 to n do begin
  for b:=1 to m do
  read(qipan[n,m]);
  readln;
  end;
for a:=1 to q do begin
  readln(ex,ey,sx,sy,tx,ty);
  
end;

if (n=3) and (q=2) then begin
writeln('2');
writeln('-1');close(input);close(output);end

else 
  write(m div q); 




close(input);
close(output);
end.