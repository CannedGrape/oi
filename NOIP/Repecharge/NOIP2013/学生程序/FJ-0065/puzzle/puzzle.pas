const dx:array[1..4]of longint=(1,0,-1,0);
      dy:array[1..4]of longint=(0,-1,0,1);
var bo,co:array[0..40,0..40]of boolean;
    i,j,k,n,m,ex,ey,sx,sy,tx,ty,ans,q,tt:longint;
procedure dfs(t,kx,ky,x,y:longint);
var i,xx,yy:longint;
begin
 if t>=ans then exit;
 if t>=tt then exit;
 for i:=1 to 4 do
  begin
   xx:=kx+dx[i]; yy:=ky+dy[i];
   if (xx>=1)and(xx<=n)and(yy>=1)and(yy<=m)and(bo[xx,yy]) then
    begin
     if (xx=x)and(yy=y)and(tx=kx)and(ty=ky) then
      begin
       if t+1<ans then ans:=t+1;
       exit;
      end;
     if (xx<>x)or(yy<>y) then
      dfs(t+1,xx,yy,x,y)
      else if(xx=x)and(yy=y) then dfs(t+1,x,y,kx,ky);
    end;
  end;
end;
function check(x,y:longint):boolean;
var x1,y1,x2,y2:longint;
begin
  x1:=x+dx[3]; y1:=y+dy[3];
  x2:=x+dx[1]; y2:=y+dy[1];
  if (not bo[x1,y1])and(not bo[x2,y2]) then exit(false);
  x1:=x+dx[2]; y1:=y+dy[2];
  x2:=x+dx[4]; y2:=y+dy[4];
  if (not bo[x1,y1])and(not bo[x2,y2]) then exit(false);
  exit(true);
end;
begin
assign(input,'puzzle.in');reset(input);
assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
  begin
   for j:=1 to m do
    begin
     read(k);
     if k=1 then bo[i,j]:=true;
    end;   readln;
  end;
  if n>m then tt:=n*3 else tt:=m*3;
  for i:=1 to q do
   begin
     ans:=99999999;
     readln(ex,ey,sx,sy,tx,ty);
     if check(tx,ty) then
     begin
      dfs(0,ex,ey,sx,sy);
      writeln(ans);
     end
      else writeln(-1);
   end ;
  close(input); close(output);
end.