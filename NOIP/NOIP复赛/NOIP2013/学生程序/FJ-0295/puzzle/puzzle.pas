program puzzle;
var map:array[0..31,0..31]of longint;
    bo:array[0..31,0..31]of boolean;
    n,m,q,ex,ey,sx,sy,tx,ty,i,j:longint;
begin
    assign(input,'puzzle.in');
    assign(output,'puzzle.out');
    reset(input);
    rewrite(output);
    readln(n,m,q);
    for i:=1 to n do
    begin
      for j:=1 to m do read(map[i,j]);
      readln;
    end;
    for i:=1 to q do
    begin
      fillchar(bo,sizeof(bo),false);
      readln(ex,ey,sx,sy,tx,ty);
      if (sx=tx) and (sy=ty) then writeln('0')
      else writeln('-1');
    end;
    close(input);
    close(output);
end.