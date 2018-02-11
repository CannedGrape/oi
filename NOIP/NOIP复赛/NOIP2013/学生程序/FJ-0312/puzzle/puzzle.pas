//program puzzle;
const fx:array[1..4,1..2]of integer=((1,0),(-1,0),(0,1),(0,-1));
      md=2139062143;
var i,j,n,m,k,ex,ey,sx,sy,tx,ty,q:longint;
    puzzle,space:array[0..35,0..35]of longint;
function map(x,y:longint):boolean;
begin if(x>0)and(y>0)and(x<=n)and(y<=m)then exit(true);exit(false);end;
procedure dfs(x,y:longint);
var i,p,q:longint;
begin

  for i:=1 to 4 do
  begin

    p:=x+fx[i,1];q:=y+fx[i,2];

    if map(p,q)and(puzzle[p,q]>0)and(space[p,q]>space[x,y]+1)then
    begin
      space[p,q]:=space[x,y]+1;
      dfs(p,q);
    end;
  end;
end;
function wrong(x,y:longint):boolean;
var i,p,q,way:longint;
begin
  way:=0;
  for i:=1 to 4 do
  begin
    p:=x+fx[i,1];q:=y+fx[i,2];
    if map(p,q)and(puzzle[p,q]>0)then inc(way);
    if way>1 then exit(false);
  end;
  exit(true);
end;
begin
assign(input,'puzzle.in');reset(input);
assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
  begin
    for j:=1 to m do read(puzzle[i,j]);
    readln;
  end;
  for i:=1 to q do
  begin
    fillchar(space,sizeof(space),$7f);
    readln(ex,ey,sx,sy,tx,ty);
    puzzle[ex,ey]:=0;
    space[ex,ey]:=0;
    dfs(ex,ey);
    puzzle[ex,ey]:=1;
    if(space[sx,sy]=md)or(space[tx,ty]=md)then
    begin
      write(-1);
      writeln;
      continue;
    end;
    if wrong(sx,sy)or wrong(tx,ty)then
    begin
      write(-1);
      writeln;
      continue;
    end;
    if(sx=tx)or(sy=ty)then write(space[sx,sy]+space[tx,ty]-1)
    else write(space[sx,sy]+space[tx,ty]+1);
    writeln;
  end;

close(input);close(output);
end.
