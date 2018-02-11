const dx:array[1..4]of integer=(0,0,1,-1);
      dy:array[1..4]of integer=(1,-1,0,0);
var
  h:array[0..10000,1..5] of longint;
  map:array[0..31,0..31] of longint;
  n,m,q,i,j,exi,eyi,sxi,syi,txi,tyi:longint;
  bo:boolean;
procedure guangsou;
var
  t,w,i,x,y:longint;
begin
  t:=1; w:=1; h[1,1]:=exi; h[1,2]:=eyi; h[1,3]:=0;
  while t<=w do
  begin
    for i:=1 to 4 do
    begin
      x:=h[t,1]+dx[i]; y:=h[t,2]+dy[i];
      if (map[x,y]=1)
      and (x>0)
      and(x<=n)
      and (y>0)
      and (y<=m)
      and ((h[t,4]<>x)
      or (h[t,5]<>y)) then
      begin
        map[x,y]:=0;
        map[h[t,1],h[t,2]]:=1;
        inc(w);
        h[w,1]:=x; h[w,2]:=y; h[w,3]:=h[t,3]+1;
        if h[w,3]>5000 then exit;
        h[w,4]:=h[t,1]; h[w,5]:=h[t,2];
        if (h[t,1]=txi) and (h[t,2]=tyi) and (x=sxi) and (y=syi) then
        begin
          bo:=true;
          writeln(h[w,3]);
          exit;
        end;
      end;
    end;
    inc(t);
  end;
end;
begin
assign(input,'puzzle.in'); reset(input);
assign(output,'puzzle.out'); rewrite(output);
  read(n,m,q);
  for i:=1 to n do
  for j:=1 to m do
  read(map[i,j]);
  for i:=1 to q do
  begin
    bo:=false;
    read(exi,eyi,sxi,syi,txi,tyi);
    guangsou;
    if not(bo) then writeln(-1);
  end;
close(input); close(output);
end.
