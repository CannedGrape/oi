var n,m,q,i,j,ex,ey,sx,sy,tx,ty,s,k,x,y,d,t:longint;
    bo:boolean;
    a,f:array[0..31,0..31] of longint;
    xx,yy:array[1..4] of integer;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  xx[1]:=1;xx[2]:=0;xx[3]:=-1;xx[4]:=0;
  yy[1]:=0;yy[2]:=1;yy[3]:=0;yy[4]:=-1;
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
  for i:=1 to q do
  begin
    readln(ex,ey,sx,sy,tx,ty);
    bo:=false; s:=0;
    for k:=1 to 4 do
      if (a[tx+xx[k],ty+yy[k]]=1) then
      begin
        bo:=true;
        break;
      end
      else inc(s);
    if (bo=false) or (s>=2) then writeln(-1)
    else writeln(tx-sx+ty-sy+1);
  end;
  close(input);close(output);
end.





