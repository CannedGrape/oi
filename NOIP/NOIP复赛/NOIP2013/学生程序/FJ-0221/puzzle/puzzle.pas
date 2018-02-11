var n,m,q,i,j,ex,ey,sx,sy,tx,ty,ans,k,c:longint;
    x1,x2,y1,y2:longint;
    a:array[0..30,0..30] of integer;
    p,o:boolean;

begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);


  readln(n,m,q);

  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);

  for i:=1 to q do begin
    readln(ex,ey,sx,sy,tx,ty);
    if (a[tx,ty]=0) then begin
      writeln('-1');
      continue;
    end;

    if a[tx,ty-1]=0 then inc(c);
    if a[tx,ty+1]=0 then inc(c);
    if a[tx+1,ty]=0 then inc(c);
    if a[tx-1,ty]=0 then inc(c);

    if c>2 then begin
      writeln('-1');
      continue;

    end;


    ans:=abs((ex-tx)+(ey-ty))+abs((sx-tx)+(sy-ty));

    if (ex>tx) then begin
      x1:=tx;
      x2:=ex;
    end
    else begin
      x1:=ex;
      x2:=tx;
    end;

    if (ey>ty) then begin
      y1:=ty;
      y2:=ey;
    end
    else begin
      y1:=ey;
      y2:=ty;
    end;

    for k:=x1 to x2 do begin
      p:=false;
      for j:=y1 to y2 do
        if a[k,j]=1 then p:=true;
      if not p then begin
        writeln('-1');
        o:=true;
        break;
      end;
    end;

    if o then continue;

    o:=false;

    if (sx>tx) then begin
      x1:=tx;
      x2:=sx;
    end
    else begin
      x1:=sx;
      x2:=tx;
    end;

    if (sy>ty) then begin
      y1:=ty;
      y2:=sy;
    end
    else begin
      y1:=sy;
      y2:=ty;
    end;

    for k:=x1 to x2 do begin
      p:=false;
      for j:=y1 to y2 do
        if a[k,j]=1 then p:=true;
      if not p then begin
        writeln('-1');
        o:=true;
        break;
      end;
    end;

    if o then continue;

    writeln(ans);

  end;
  close(input);
  close(output);
end.
