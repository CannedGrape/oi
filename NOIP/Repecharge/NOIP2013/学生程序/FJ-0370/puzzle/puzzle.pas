program puzzle;
const dx:array[1..4] of -1..1=(-1,0,1,0);
      dy:array[1..4] of -1..1=(0,-1,0,1);
var
  i,j,n,m,q,x1,x2,y1,y2,t,w:longint;
  a:array[0..50,0..50] of longint;
  b:array[0..500,0..10] of longint;
  bo,bd:array[0..50,0..50] of boolean;
  r:array[0..1000,0..2] of longint;
  d:array[0..1000,0..2] of longint;
function sch(l,r:longint):boolean;
var i,x,y:integer;
begin
  for i:=1 to 4 do
  begin
    x:=l+dx[i]; y:=r+dy[i];
    if (x=d[w,1]) and (y=d[w,2]) then exit(true);
  end;
  exit(false);
end;
function sch2(l,r:longint):boolean;
var i,x,y:integer;
begin
  for i:=1 to 4 do
  begin
    x:=l+dx[i]; y:=r+dy[i];
    if bo[x,y]  then exit(true);
  end;
  exit(false);
end;
procedure gs(x,y:longint);
var i,x0,y0:integer;
begin
  t:=1; w:=0;
  r[t,1]:=x; r[t,2]:=y; bd[x,y]:=false;
  d[t,1]:=x1; d[t,2]:=y1;
  repeat
  if (r[w,1]=d[w,1]) and (r[w,2]=d[w,2]) and sch(r[w,1],r[w,2]) then begin writeln(r[w,0]+1); exit; end;
  for i:=1 to 4 do
  begin
    x0:=r[t,1]+dx[i]; y0:=r[t,2]+dy[i];
    if bo[x0,y0] and bd[x0,y0] and (x0>0) and (x0<=n) and (y0>0) and (y0<=m) then
     begin
       inc(w);
       r[w,1]:=x0; r[w,2]:=y0; r[w,0]:=r[t,0]+1;
       if (x0=d[t,1]) and (y0=d[t,2]) then
       begin
         d[w,1]:=r[t,1]; d[w,2]:=r[t,2];
       end
       else d[w,1]:=d[t,1]; d[w,2]:=d[t,2];
       bd[x0,y0]:=false;
     end;
  end;
     inc(t);
  until t>w;
end;
begin
  assign(input,'puzzle.in');  reset(input);
  assign(output,'puzzle.out');  rewrite(output);
  readln(n,m,q);
  fillchar(bo,sizeof(bo),true);
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      read(a[i,j]);
      if a[i,j]=1 then bo[i,j]:=true
      else bo[i,j]:=false;
    end;
    readln;
  end;
  for i:=1 to q do
  begin
    for j:=1 to 6 do
      read(b[i,j]);
    readln;
  end;
  for i:=1 to q do
  begin
    x1:=b[i,3]; y1:=b[i,4];
    x2:=b[i,5]; y2:=b[i,6];
    if (not sch2(b[i,1],b[i,2])) or (not sch2(x1,y1)) then
      writeln(-1)
    else begin fillchar(bd,sizeof(bd),true); fillchar(r,sizeof(r),0); fillchar(d,sizeof(d),0); gs(b[i,1],b[i,2]); end;
  end;
  close(input);  close(output);
end.