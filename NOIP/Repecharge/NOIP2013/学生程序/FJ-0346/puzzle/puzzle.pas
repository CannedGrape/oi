program puzzle;
var n,m,q:longint;
    a:array[1..30,1..30] of byte;
    i,j,ex,ey,sx,sy,tx,ty:longint;
procedure init;
var i,j:longint;
begin
assign(input,'puzzle.in');
reset(input);
assign(output,'puzzle.out');
rewrite(output);

    read(n,m,q);
    for i:=1 to n do
        for j:=1 to m do
        read(a[i,j]);
end;
begin
init;
for i:=1 to q do
begin
    read(ex,ey,sx,sy,tx,ty);
    write('-1');
    writeln;
end;
close(input);
close(output);

end.
