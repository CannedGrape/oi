const Ln=32;
      Ld=Ln*Ln;
      p:array[1..4,0..1]of -1..1=((1,0),(-1,0),(0,1),(0,-1));
type znode=record x,y,kx,ky,s,f:longint; end;
var a,b:array[0..Ln,0..Ln]of longint;
    c:array[0..Ln,0..Ln,1..4]of longint;
    z:array[0..2000000]of znode;
    d:array[0..Ld,1..2]of longint;
    n,m,q,t,tx,ty:longint;
//
Procedure heap(x:longint);
  var r:znode;
  begin
    if t=0 then exit;
    r:=z[x];x:=x*2;
    while x<=t do
    begin
      if (x<t)and(z[x].f>z[x+1].f) then inc(x);
      if z[x].f>=r.f then break;
      z[x shr 1]:=z[x];
      x:=x*2;
    end;
    x:=x shr 1;z[x]:=r;
    while x>1 do
    begin
      if z[x shr 1].f<=r.f then break;
      z[x]:=z[x shr 1];
      x:=x shr 1;
    end;
    z[x]:=r;
  end;
Function cost(x,y:longint):longint;
  var l,r,i,nx,ny:longint;
  begin
    fillchar(b,sizeof(b),$ff);
    l:=1;r:=1;d[1][1]:=x;d[1][2]:=y;b[x][y]:=0;
    while l<=r do
    begin
      x:=d[l][1];y:=d[l][2];
      for i:=1 to 4 do
      begin
        nx:=x+p[i][0];
        ny:=y+p[i][1];
        if (a[nx][ny]=0)or(b[nx][ny]<>-1)
        or ((nx=z[1].x)and(ny=z[1].y)) then continue;
        b[nx][ny]:=b[x][y]+1;
        if (nx=z[1].kx)and(ny=z[1].ky) then exit(b[nx][ny]);
        inc(r);d[r][1]:=nx;d[r][2]:=ny;
      end;
      inc(l);
    end;
    exit(-1);
  end;
//
Procedure Init;
  var i,j:longint;
  begin
    fillchar(a,sizeof(a),0);
    readln(n,m,q);
    for i:=1 to n do
      for j:=1 to m do read(a[i][j]);
  end;
//
Procedure Solve;
  var i,nx,ny,v,tot:longint;
  begin
    with z[1] do
      repeat
        fillchar(c,sizeof(c),$7f);
        readln(kx,ky,x,y,tx,ty);
        if (a[tx][ty]=0)or(a[x][y]=0) then writeln(-1)
        else begin

        s:=0;f:=abs(x-tx)+abs(y-ty);
        t:=1; tot:=0;
        while (f>s)and(t>0) do
        begin
          for i:=1 to 4 do
          begin
            nx:=x+p[i][0];
            ny:=y+p[i][1];
            if (a[nx][ny]=0)or((nx=kx)and(ny=ky)) then continue;
            v:=s+cost(nx,ny)+1;
            if (v>s)and(c[nx][ny][i]>v) then
            begin
              c[nx][ny][i]:=v;
              inc(t);inc(tot);
              z[t].x:=nx;z[t].kx:=x;
              z[t].y:=ny;z[t].ky:=y;
              z[t].s:=v;
              z[t].f:=abs(nx-tx)+abs(ny-ty)+v;
              heap(t);
            end;
          end;
          z[1]:=z[t];dec(t);heap(1);
        end;
        if f=s then writeln(s) else writeln(-1);

        end;
        dec(q);
      until q<=0;
  end;
//
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  //
  Init;
  Solve;
  //
  close(Input);close(output);
end.
