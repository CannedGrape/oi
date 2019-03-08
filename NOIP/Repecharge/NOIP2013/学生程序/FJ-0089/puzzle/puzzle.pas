var
  a:array[0..100,0..100]of longint;
  b:array[1..4]of longint=(1,-1,0,0);
  c:array[1..4]of longint=(0,0,1,-1);
  f:array[0..100,0..100]of boolean;
  ex,ey,sx,sy,tx,ty,t1,t,t2,m,m1,m2,n,q,s,i,j,k:longint;

procedure ss(i,j,t:longint);
begin
  if (i=tx)and(j=ty) then
  begin
  if t<s then s:=t;end
  else
    for k:=1 to 4 do
    begin
      i:=i+b[k];j:=j+c[k];
      if (i>0) and (i<=n) and (j>0) and (j<=m)
      then begin
      if f[i,j] then
      begin

       ss(i,j,t+2);end;
      i:=i-b[k];j:=j-c[k];
      end;
    end;
end;


begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  fillchar(f,sizeof(f),false);
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(a[i,j]);
      if a[i,j]=1 then f[i,j]:=true;
    end;
  for i:=1 to q do
  begin
    t1:=0;t2:=0;
    readln(ex,ey,sx,sy,tx,ty);
    for k:=1 to 4 do
    begin
      if f[sx+b[k],sy+c[k]]=false then inc(t1);
      if f[tx+b[k],ty+c[k]]=false then inc(t2);
    end;
    if (t1>=3) or (t2>=3) then writeln(-1)
    else
    begin
      s:=maxlongint;
      ss(sx,sy,0);
      writeln(s);
    end;
  end;
  close(input);close(output);
end.
