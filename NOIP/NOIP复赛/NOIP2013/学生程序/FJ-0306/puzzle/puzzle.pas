program ex_3;
const dx:array[1..4] of -1..1=(1,-1,0,0);
      dy:array[1..4] of -1..1=(0,0,1,-1);
var d:array[0..31,0..31]of longint;
    n,m,q,i,j,ans,x1,y1,x2,y2,x3,y3,xx,yy:longint;
procedure dfs;
var i,j,k,u,v:longint;
begin
  if (xx=x3)and(yy=y3) then
    begin
      if j<ans then ans:=j;
    end
  else
  for i:=1 to n do
    for j:=1 to m do
      for k:=1 to 4 do
        begin
          if d[i,j]<>0 then
        end;
end;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  read(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      read(d[i,j]);


  for i:=1 to q do
    begin
      read(x1,y1,x2,y2,x3,y3);
      ans:=maxlongint;
      dfs;
      ans:=-1;
      write(ans);
    end;
  close(input);
  close(output);
end.
