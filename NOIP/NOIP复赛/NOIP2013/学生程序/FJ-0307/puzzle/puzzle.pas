const x:array[1..4] of longint=(1,-1,0,0);
      y:array[1..4] of longint=(0,0,1,-1);
var qq:array[1..820000,1..4] of longint;
    a,z:array[1..30,1..30] of longint;
    ex,ey,sx,sy,tx,ty,i,j,tot,n,m,q:longint;
    b:array[1..30,1..30] of boolean;
function bfs(ex,ey,sx,sy,tx,ty:byte):longint;
     var head,wei,i,xx,yy,ci,zgs,min:longint;
begin
  fillchar(qq,sizeof(qq),0); fillchar(b,sizeof(b),0);
  qq[1,1]:=ex; qq[1,2]:=ey; qq[1,3]:=0; qq[1,4]:=0;
  wei:=1;  head:=0; min:=maxlongint;
  repeat
   inc(head); xx:=qq[head,1]; yy:=qq[head,2];
              ci:=qq[head,3]; zgs:=qq[head,4];
   for i:=1 to 4 do
    if (xx+x[i]>0) and (xx+x[i]<=n) and (yy+y[i]>0) and (yy+y[i]<=m)
    and (a[xx+x[i],yy+y[i]]=1) and (not b[xx+x[i],yy+y[i]]) and (ci+1<min)
    then
    begin
     if (zgs=z[tx,ty]) and (xx+x[i]=sx) and (yy+y[i]=sy) then
      begin
       if min>ci+1 then min:=ci+1;
       continue;
      end;
     inc(wei); qq[wei,1]:=xx+x[i]; qq[wei,2]:=yy+y[i];
               qq[wei,3]:=ci+1;   qq[wei,4]:=z[xx+x[i],yy+y[i]];
               b[xx+x[i],yy+y[i]]:=true;
    end;
  until head>=wei;
  if min=maxlongint then exit(-1) else exit(min);
end;

begin
  assign(input,'puzzle.in'); reset(input);
  assign(output,'puzzle.out'); rewrite(output);
  readln(n,m,q); tot:=0;
  for i:=1 to n do
   begin
    for j:=1 to m do
     begin
      read(a[i,j]);
      if a[i,j]=1 then begin inc(tot); z[i,j]:=tot; end;
     end;
    readln;
   end;

  for i:=1 to q do
   begin
    readln(ex,ey,sx,sy,tx,ty);
    if (sx=tx) and (sy=ty) then begin writeln(0); continue; end;
    if ((a[ex,ey]=0) or (a[sx,sy]=0) or (a[tx,ty]=0)) then begin writeln(-1); continue; end;
    writeln(bfs(ex,ey,sx,sy,tx,ty));
   end;
  close(input); close(output);
end.
