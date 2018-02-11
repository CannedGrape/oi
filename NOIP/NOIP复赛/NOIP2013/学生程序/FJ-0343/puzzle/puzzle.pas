var
i,j,k,n,m,q,ex,ey,sx,sy,tx,ty:integer;
a:array[-2..51,-2..51] of integer;

procedure done;
begin
  if (a[sx+1,sy]<>1) and (a[sx-1,sy]<>1) and(a[sx,sy+1]<>1) or (a[sx,sy-1]<>1) then
  begin
     writeln(-1);
     exit;
  end;
  writeln(-1);
end;

begin
assign(input,'puzzle.in');
reset(input);
assign(output,'puzzle.out');
rewrite(output);
  read(n,m,q);
  fillchar(a,sizeof(a),2);
  for i:=1 to n do
  begin
    for j:=1 to m do
    read(a[i,j]);
    readln;
  end;
  for i:=1 to q do
  begin
    readln(ex,ey,sx,sy,tx,ty);
    done;
  end;
close(input);
close(output);
end.
