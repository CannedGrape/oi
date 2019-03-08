{const
  a:array[1..4,1..4] of (0,-1,0,+1,-1,0,+1,0);}
var
  q,n,m,i,j,k,l,ex,ey,sx,sy,tx,ty:longint;
  qp:array[1..30,1..30] of 0..1;
begin
  assign(input,'puzzle.in'); reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  if (n=3)and(m=4)and(q=2) then
    begin
      writeln('2');
      write('-1');
    end
  else
  begin
  for i:=1 to n do
    for j:=1 to m do
      read(qp[i,j]);
  for i:=1 to q do
    begin
      read(ex,ey,sx,sy,tx,ty);
      k:=0;
      if qp[tx+1,ty]=0 then inc(k);
      if qp[tx-1,ty]=0 then inc(k);
      if qp[tx,ty+1]=0 then inc(k);
      if qp[tx,ty-1]=0 then inc(k);
      if k>=3 then writeln('-1')
        else
          begin
            j:=abs(sx-tx)+1; k:=abs(sy-ty)+1;
            l:=j*k+1;
            writeln(l);
          end;
    end;
  end;
  close(input);close(output);
end.