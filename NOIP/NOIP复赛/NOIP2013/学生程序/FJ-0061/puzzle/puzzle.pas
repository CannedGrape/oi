uses math;
var n,mm,q,i,j,step,ans,x,sx,sy,ex,ey,tx,ty:longint;
    m:array[-1..35,-1..35] of boolean;

    u:array[1..4]of integer=(-1,1,0,0);
    v:array[1..4]of integer=(0,0,-1,1);

procedure bj(x,y:integer);
begin
    m[x,y]:=true;
end;
procedure qx(x,y:integer);
begin
    m[x,y]:=false;
end;
procedure d(x1,y1,x2,y2:integer);
var i,q:integer;
begin
    step:=-1;
    bj(x2,y2);
    q:=30000;
    if (x1=sx)and(y1=sy)and(x2=ex)and(y2=ey) then begin step:=1;qx(x2,y2);exit;end;
    if (not m[x1,y1]) then begin step:=-1;d(x2,y2,x1,y1);if step>0 then q:=min(q,step+1);end;
    for i:=1 to 4 do
     if (x2+u[i]<=n)and(y2+v[i] <=mm)and(not m[x2+u[i],y2+v[i]]) then begin step:=-1;d(x1,y1,x2+u[i],y2+v[i]);if step>0 then q:=min(q,step+1);end;
    if q<30000 then step:=q;
    qx(x2,y2);

end;
begin
    assign(input,'puzzle.in');reset(input);
    assign(output,'puzzle.out');rewrite(output);
    readln(n,mm,q);
    for i:=1 to n do
     for j:=1 to mm do
     begin
      read(x);
      if x=0 then bj(i,j) else qx(i,j);
     end;
    for i:=1 to q do
    begin
     read(ex,ey,sx,sy,tx,ty);
     if (not m[tx-1,ty]) then d(tx,ty,tx-1,ty);if step>0 then ans:=min(ans,step);
     if (not m[tx-1,ty]) then d(tx,ty,tx+1,ty);if step>0 then ans:=min(ans,step);
     if (not m[tx-1,ty]) then d(tx,ty,tx,ty-1);if step>0 then ans:=min(ans,step);
     if (not m[tx-1,ty]) then d(tx,ty,tx,ty+1);if step>0 then ans:=min(ans,step);
     if ans<=0 then ans:=-1;
     writeln(ans);
    end;
    close(input);close(output);
end.
