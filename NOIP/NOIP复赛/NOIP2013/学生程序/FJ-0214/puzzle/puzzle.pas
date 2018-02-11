const
  fx:array[1..4,1..2]of integer=((-1,0),(1,0),(0,1),(0,-1));
var
  n,m,i,j,x,ex,ey,sx,sy,tx,ty,q,ans:longint;
  flag1,flag2:array[-10..30,-10..30]of integer;
  flag3:boolean;
procedure search(dep,lastx,lasty,whitex,whitey:longint);
var
  i,xx,yy,m,fuck:longint;
begin
  if (lastx=tx) and (lasty=ty) and (whitex=sx) and (whitey=sy) then begin if dep<ans then ans:=dep; end;
  if dep>100000 then begin if (ans=maxlongint) and (not flag3) then begin writeln(-1); flag3:=true; exit; end else begin if not flag3 then begin writeln(ans-1); flag3:=true; end; exit; end; end;
  if not flag3 then
  begin
  for i:=1 to 4 do
   begin
     xx:=whitex+fx[i,1];
     yy:=whitey+fx[i,2];
     if (flag1[xx,yy]<>0) and ((xx<>lastx) or (yy<>lasty)) then
     begin
       m:=flag1[whitex,whitey];
       fuck:=flag1[xx,yy];
       flag1[whitex,whitey]:=flag1[xx,yy];
       flag1[xx,yy]:=2;
       search(dep+1,whitex,whitey,xx,yy);
       flag1[xx,yy]:=fuck;
       flag1[whitex,whitey]:=m;;
     end;
     xx:=whitex-fx[i,1];
     yy:=whitey-fx[i,2];
   end;
  end;
end;

begin
  assign(input,'puzzle.in'); reset(input);
  assign(output,'puzzle.out'); rewrite(output);
  fillchar(flag1,sizeof(flag1),0);
  readln(n,m,q);
  for i:=1 to n do
   for j:=1 to m do
   begin
     read(x);
     if x=1 then flag1[i,j]:=1 else flag1[i,j]:=0;
   end;
   flag2:=flag1;
  for i:=1 to q do
   begin
     readln(ex,ey,sx,sy,tx,ty);
     flag1:=flag2;
     flag3:=false;
     ans:=maxlongint;
     flag1[ex,ey]:=2;
     flag1[sx,sy]:=3;
     flag1[tx,ty]:=4;
     search(1,0,0,ex,ey);
   end;
  close(input); close(output);
end.
