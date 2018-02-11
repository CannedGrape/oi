const dx:array[1..4]of longint=(0,0,1,-1);
      dy:array[1..4]of longint=(1,-1,0,0);
var check:array[0..30,0..30,0..30,0..30]of boolean;
    h:array[0..1000000,0..4]of longint;
    step:array[0..1000000]of longint;
    map:array[0..30,0..30]of longint;
    l,r,n,m,q,ex,ey,sx,sy,tx,ty,i,j,k:longint;
function bfs:longint;
var i,j,k,tx,ty:longint;
begin
  while l<r do
    begin
      inc(l);
      for i:=1 to 4 do
        begin
          tx:=h[l,1]+dx[i];  ty:=h[l,2]+dy[i];
          if (tx in [1..n])and(ty in [1..m]) then
            begin
              if (h[l,3]=tx)and(h[l,4]=ty)and(check[tx,ty,h[l,1],h[l,2]]=false) then
                begin
                  inc(r);
                  h[r,1]:=tx;  h[r,2]:=ty;
                  h[r,3]:=h[l,1];  h[r,4]:=h[l,2];
                  check[h[r,1],h[r,2],h[r,3],h[r,4]]:=true;
                  step[r]:=step[l]+1;
                  if map[h[r,3],h[r,4]]=2 then exit(step[r]);
                end else
              if (map[tx,ty]<>0)and(check[tx,ty,h[l,3],h[l,4]]=false) then
                begin
                  inc(r);
                  h[r,1]:=tx;  h[r,2]:=ty;
                  h[r,3]:=h[l,3];  h[r,4]:=h[l,4];
                  check[tx,ty,h[l,3],h[l,4]]:=true;
                  step[r]:=step[l]+1;
                end;
            end;
        end;
    end;
  exit(-1);
end;
begin
assign(input,'puzzle.in');assign(output,'puzzle.out');
reset(input);rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do read(map[i,j]);
  for i:=1 to q do
    begin
      l:=0;  r:=1;
      fillchar(check,sizeof(check),0);
      fillchar(step,sizeof(step),0);
      readln(ex,ey,sx,sy,tx,ty);
      map[tx,ty]:=2;
      h[1,1]:=ex;  h[1,2]:=ey;  h[1,3]:=sx;  h[1,4]:=sy;
      check[ex,ey,sx,sy]:=true;
      if (tx=sx)and(ty=sy) then writeln(0) else writeln(bfs);
      map[tx,ty]:=1;
    end;
close(input);close(output);
end.
