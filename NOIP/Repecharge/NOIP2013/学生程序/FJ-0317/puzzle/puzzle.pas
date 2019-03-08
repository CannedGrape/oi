var n,m,q,i,j,k,s:longint;
    a:array[0..32,0..32]of longint;
    ex,ey,sx,sy,tx,ty:array[0..502]of longint;
procedure work(x1,y1,x2,y2,x3,y3:longint);
var i,j,k,y,t:longint;
begin
 k:=0;
 if a[x3-1,y3]=0 then inc(k);
 if a[x3,y3-1]=0 then inc(k);
 if a[x3+1,y3]=0 then inc(k);
 if a[x3,y3+1]=0 then inc(k);
 if k>2 then
 begin
  if (x1=x3)and(y1=y3) then
  begin
   if (x2=x3+1)and(y2=y3) then s:=1;
   if (x2=x3-1)and(y2=y3) then s:=1;
   if (x2=x3)and(y2=y3+1) then s:=1;
   if (x2=x3)and(y2=y3-1) then s:=1;
  end;
  if s=1 then writeln(1)
  else writeln(-1);
 end
 else
 begin
  if y1>y3 then y:=y1 else y:=y3;
  t:=0;
  if x1>x3 then
  begin
   for i:=x3 to x1 do
    for j:=y to m do
    if a[i,j]=0 then inc(t);
  end
  else
  begin
   for i:=x1 to x3 do
    for j:=y to m do
    if a[i,j]=0 then inc(t);
  end£»
  s:=(abs(x3-x2)+abs(y3-y2))*(abs(x3-x2)+abs(y3-y2)+abs(x3-x1)+abs(y3-y1)+t);
  writeln(s);
 end;
end;
begin
 assign(input,'puzzle.in');reset(input);
 assign(output,'puzzle.out');rewrite(output);
 readln(n,m,q);
 for i:=0 to n+1 do
  for j:=0 to m+1 do
   a[i,j]:=0;
 for i:=1 to n do
 begin
  for j:=1 to m do read(a[i,j]);
  readln;
 end;
 for i:=1 to n do
  for j:=1 to m do
  begin
   k:=0;
   if a[i-1,j]=0 then inc(k);
   if a[i,j-1]=0 then inc(k);
   if a[i+1,j]=0 then inc(k);
   if a[i,j+1]=0 then inc(k);
   if k>2 then a[i,j]:=0;
  end;
 for i:=1 to q do
 begin
  read(ex[i],ey[i],sx[i],sy[i],tx[i],ty[i]);
  readln;
  s:=0;
  a[ex[i],ey[i]]:=1;
  a[sx[i],sy[i]]:=1;
  a[tx[i],ty[i]]:=1;
  if (sx[i]=tx[i])and(sy[i]=ty[i]) then writeln(s);
  work(ex[i],ey[i],sx[i],sy[i],tx[i],ty[i]);
 end;
 close(input);close(output);
end.