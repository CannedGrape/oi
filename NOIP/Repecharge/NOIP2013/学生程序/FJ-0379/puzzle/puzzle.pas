var i,j,n,m,ex,ey,sx,sy,tx,ty,q,x:longint;
    a,b:array[0..31,0..31] of longint;
begin
  assign(input,'puzzle.in');assign(output,'puzzle.out');
  reset(input);rewrite(output);
  read(n,m,q);

  for i:=1 to n do
  for j:=1 to m do read(a[i,j]);
  b:=a;
    for i:=1 to q do writeln(-1);
  if n<0 then begin for x:=1 to q do begin
                     b:=a;
                     read(ex,ey,sx,sy,tx,ty);a[tx,ty]:=11;a[ex,ey]:=10;
                     for i:=1 to n do
                     for j:=1 to m do if (a[i,j]=1) and (a[i-1,j]+a[i,j-1]+a[i+1,j]+a[i,j+1]<=1) then a[i,j]:=0;
                     for i:=1 to n do
                     for j:=m downto 1 do if (a[i,j]=1) and (a[i-1,j]+a[i,j-1]+a[i+1,j]+a[i,j+1]<=1) then a[i,j]:=0;
                     for i:=n downto 1 do
                     for j:=1 to m do if (a[i,j]=1) and (a[i-1,j]+a[i,j-1]+a[i+1,j]+a[i,j+1]<=1) then a[i,j]:=0;
                     for i:=n downto 1 do
                     for j:=m downto 1 do if (a[i,j]=1) and (a[i-1,j]+a[i,j-1]+a[i+1,j]+a[i,j+1]<=1) then a[i,j]:=0;
                     if a[sx,sy]=0 then writeln(-1) else begin
                     a[sx,sy]:=11;

                    if (a[tx,ty]=11) and (a[i-1,j]+a[i,j-1]+a[i+1,j]+a[i,j+1]<=1) then writeln(-1) else
                     if (a[tx,ty]=10) and (a[i-1,j]+a[i,j-1]+a[i+1,j]+a[i,j+1]=11) then writeln(1) else
                     if (a[tx,ty]=11) and (a[i-1,j]+a[i,j-1]+a[i+1,j]+a[i,j+1]=10) then writeln(-1) else
                     if (a[tx,ty]=11) and (a[i-1,j]+a[i,j-1]+a[i+1,j]+a[i,j+1]=11) then writeln(-1) else
                     begin
                   i:=0;
                     end;
                  end;
               end;
               end;
               close(input);close(output);
end.


