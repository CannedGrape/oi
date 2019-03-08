program puzzle;
var a:array[0..30,0..30] of integer;
    ex,b,ey,sx,sy,tx,ty:array[1..1000]of integer;
    i,j,k,n,m,q,p:integer;
begin
assign(input,'puzzle.in');
assign(output,'pizzle.out');
reset(input);
rewrite(output);
readln(n,m,p); fillchar(a,sizeof(a),0);
for i:=1 to n do
begin
for j:=1 to m do read(a[i,j]);
readln
end;
for i:=1 to q do
begin
readln(ex[i],ey[i],sx[i],sy[i],tx[i],ty[i]);
a[ex[i],ey[i]]:=2; a[sx[i],sy[i]]:=3; a[tx[i],ty[i]]:=4;
b[i]:=-1;
end;
for i:=1 to q do writeln(b[i]);
close(input);
close(output);
end.
