var n,m,q,ex,ey,sx,sy,tx,ty,minx,miny,maxx,maxy,i,j,zz:integer;
    t1,t2,tt:longint;
    a:array[0..31,0..31] of integer;

//______________________________________
procedure iin;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
end;
procedure oout;
begin
  close(input);
  close(output);
end;
//______________________________________
function sear1:boolean;
var i,j:integer;
begin
  sear1:=true;
  for i:=minx to maxx do
   for j:=miny to maxy do
    if a[i,j]=0 then exit(false);
end;
//______________________________________
//______________________________________
begin
  iin;
  readln(n,m,q);
  for i:=1 to n do
   for j:=1 to m do
    begin
     read(a[i,j]);
     if a[i,j]=1 then a[i,j]:=2;
    end;
  for i:=1 to m do begin a[0,i]:=0; a[n+1,i]:=0; end;
  for i:=1 to n do begin a[i,0]:=0; a[i,m+1]:=0; end;
  for zz:=1 to q do
   begin
    readln(ex,ey,sx,sy,tx,ty);
    a[ex,ey]:=1;
    //sear(ex.ey);
    if sx<=tx then begin minx:=sx; maxx:=tx; end
    else begin minx:=tx; maxx:=sx; end;
    if sy<=ty then begin miny:=sy; maxy:=ty; end
    else begin miny:=ty; maxy:=sy; end;
    if sear1=false then begin writeln(-1); t1:=-1; end;

    if t1<>-1 then t1:=(maxx-minx)+(maxy-miny);

    if ex<=tx then begin minx:=ex; maxx:=tx; end
    else begin minx:=tx; maxx:=ex; end;
    if ey<=ty then begin miny:=ey; maxy:=ty; end
    else begin miny:=ty; maxy:=ey; end;
    if sear1=false then begin writeln(-1); t2:=-1; end;

    if t2<>-1 then t2:=(maxx-minx)+(maxy-miny);

    if (ex=sx)and(sx=tx) then
    begin
     if (sy>ey) and (sy<ty) then begin t1:=-1; t2:=-1; end;
     if (sy>ty) and (sy<ey) then begin t1:=-1; t2:=-1; end;
    end;


    if (ey=sy)and(sy=ty) then
    begin
     if (sx>ex) and (sx<tx) then begin t1:=-1; t2:=-1; end;
     if (sx>tx) and (sx<ex) then begin t1:=-1; t2:=-1; end;
    end;

    if (t1=-1) or (t2=-1) then writeln(-1);

    if (t1<>-1) and (t2<>-1) then
    begin
     tt:=t1+t2;
     writeln(tt);
    end;
   end;
  oout;
end.


