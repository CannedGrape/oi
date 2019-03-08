const w:array[1..4,1..2]of longint=((-1,0),(1,0),(0,1),(0,-1));
var f,h:array[0..30,0..30]of longint;
    n,m,q,i,j,x0,y0,x1,y1,x2,y2,min,x,y:longint;

  procedure st(x,y,t:longint);
  var k:longint;xx,yy:longint;
  begin
    for k:=1 to 4 do
      begin
        xx:=x+w[k,1];yy:=y+w[k,2];
        if (xx>0)and(xx<=n)and(yy>0)and(yy<=m)and(h[xx,yy]=0) then
        begin
          if (f[xx,yy]=2)and(x=x2)and(y=y2) then
          begin
            if t+1<min then min:=t+1;
            exit;
          end;
          if f[xx,yy]=1 then begin h[xx,yy]:=1;st(xx,yy,t+1);h[xx,yy]:=0;end
          else if f[xx,yy]=2 then
            begin f[xx,yy]:=1;f[x,y]:=2;h[xx,yy]:=1;
                  st(xx,yy,t+1);
                  f[xx,yy]:=2;f[x,y]:=1;h[xx,yy]:=0;
            end;
        end;
      end;
  end;

begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
  begin
    for j:=1 to m do read(f[i,j]);
    readln;
  end;
  for i:=1 to q do
  begin
    fillchar(h,sizeof(h),0);
    readln(x0,y0,x1,y1,x2,y2);
    h[x0,y0]:=1;
    if f[x0,y0]=0 then begin writeln('-1');continue; end;
    if (x1=x2)and(y1=y2) then begin writeln('0');continue; end;
    min:=maxlongint;
    f[x1,y1]:=2;
    for j:=1 to 4 do
      begin
        x:=x0+w[j,1];y:=y0+w[j,2];
        if (f[x,y]=2)and(x0=x2)and(y0=y2) then
          begin writeln('1');continue; end;
        if f[x,y]=1 then st(x,y,1) else
        if f[x,y]=2 then
          begin f[x,y]:=1;f[x0,y0]:=2;st(x,y,1);f[x,y]:=2;f[x0,y0]:=1; end;
        x:=x0;y:=y0;
      end;
    if min<>maxlongint then writeln(min)
    else writeln('-1');
  end;
  close(input);close(output);
end.
