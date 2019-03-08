var
  i,j,k,m,n,ex,ey,tx,ty,sx,sy,q:longint;
  a:array[0..30,0..30] of 0..4;
  b:array[0..1000000,1..2,1..2] of 0..30;
  c:array[0..1000000] of longint;
  d:array[0..1000000] of 0..4;
function  work:longint;
  var
   ii,jj,kk,l,r,x1,y1,x2,y2:longint;
  begin
   fillchar(b,sizeof(b),0);
   fillchar(c,sizeof(c),0);
   fillchar(d,sizeof(d),0);
   if (sx=tx) and (sy=ty) then exit(0);
   b[0,1,1]:=ex;  b[0,1,2]:=ey;
   b[0,2,1]:=sx;  b[0,2,2]:=sy;
   l:=-1;  r:=0;
   while (l<r) and (r<=900000) and (r<=20*m*n*m*n)  do
     begin
      inc(l);
      x1:=b[l,1,1];  y1:=b[l,1,2];
      x2:=b[l,2,1]; y2:=b[l,2,2];
      if (y1-1>0) and (a[x1,y1-1]<>0) and (d[l]<>2)then
       begin
        inc(r); d[r]:=1;     c[r]:=c[l]+1;
        b[r,1,1]:=x1;  b[r,1,2]:=y1-1;
        b[r,2,1]:=x2;  b[r,2,2]:=y2;
        if (x2=x1)  and  (y2=y1-1)   then
          begin
           b[r,2,2]:=y1;
           if (x1=tx)  and (y1=ty)    then  exit(c[r]);
          end;
       end;
      if (y1+1<=m) and (a[x1,y1+1]<>0) and (d[l]<>1) then
       begin
        inc(r);  d[r]:=2;  c[r]:=c[l]+1;
        b[r,1,1]:=x1; b[r,1,2]:=y1+1;
        b[r,2,1]:=x2; b[r,2,2]:=y2;
        if (x1=x2)  and (y2=y1+1) then
          begin
            b[r,2,2]:=y1;
            if (x1=tx) and (y1=ty)  then   exit(c[r]);
          end;
       end;

      if (x1-1>0) and (a[x1-1,y1]<>0) and (d[l]<>4) then
       begin
         inc(r);  d[r]:=3;  c[r]:=c[l]+1;
         b[r,1,1]:=x1-1; b[r,1,2]:=y1;
         b[r,2,1]:=x2;  b[r,2,2]:=y2;
         if (x1-1=x2) and (y1=y2) then
          begin
            b[r,2,1]:=x1;
            if (x1=tx) and (y1=ty)  then   exit(c[r]);
          end;
       end;
      if (x1+1<=n) and (a[x1+1,y1]<>0) and (d[l]<>3)  then
       begin
        inc(r);  d[r]:=4;  c[r]:=c[l]+1;
        b[r,1,1]:=x1+1;   b[r,1,2]:=y1;
        b[r,2,1]:=x2;  b[r,2,2]:=y2;
        if (x1+1=x2) and (y1=y2) then
          begin
            b[r,2,1]:=x1;
            if (x1=tx) and (y1=ty) then  exit(c[r]);
          end;
       end;
    end;
   k:=-1;
   exit(k);
 end;

begin
  assign(input,'puzzle.in');  reset(input);
  assign(output,'puzzle.out');  rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
   begin
    for j:=1 to m do
     read(a[i,j]);
    readln;
   end;
  for i:=1 to q do
   begin
    read(ex,ey,sx,sy,tx,ty);
    readln;
    m:=work;
    writeln(m);
   end;
  close(input);  close(output);
end.
