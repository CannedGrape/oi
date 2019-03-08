const Ln=15000*2;
      Lm=50000;
type edge=record x,y,z:longint;end;
var v:array[0..Lm]of edge;
    f,c,deep,u,p:array[0..Ln]of longint;
    d:array[0..Ln,0..20]of longint;
    n,m,q:longint;
//
Function bcj(x:longint):longint;
  begin
    if u[x]<>x then u[x]:=bcj(u[x]);
    exit(u[x]);
  end;
//
Procedure qsort(l,r:longint);
  var i,j,m:longint;
      t:edge;
  begin
    i:=l;j:=r;m:=v[(i+j)div 2].z;
    while i<=j do
    begin
      while v[i].z>m do inc(i);
      while v[j].z<m do dec(j);
      if i<=j then
      begin
        t:=v[i];v[i]:=v[j];v[j]:=t;
        inc(i);dec(j);
      end;
    end;
    if l<j then qsort(l,j);
    if i<r then qsort(i,r);
  end;
//
Procedure Init;
  var i:longint;
  begin
    readln(n,m);
    for i:=1 to m do readln(v[i].x,v[i].y,v[i].z);
  end;
//
Procedure Make_tree;
  var i,tot,w,bx,by:longint;
  begin
    qsort(1,m); tot:=0; w:=n;
    for i:=1 to n do u[i]:=i;
    for i:=1 to m do
    begin
      bx:=bcj(v[i].x);by:=bcj(v[i].y);
      if bx<>by then
      begin
        inc(w);
        u[bx]:=w;f[bx]:=w;
        u[by]:=w;f[by]:=w;
        u[w]:=w; p[w]:=v[i].z;
        inc(tot);
        if tot=n-1 then break;
      end;
    end;
    fillchar(d,sizeof(d),0); n:=w; deep[n]:=0; deep[0]:=-1;
    for i:=n-1 downto 1 do
    begin
      deep[i]:=deep[f[i]]+1;
      d[i][0]:=f[i]; w:=0;
      while d[d[i][w]][w]>0 do
      begin
        d[i][w+1]:=d[d[i][w]][w];
        inc(w);
      end;
    end;
  end;
//
Function Lca(x,y:longint):longint;
  var l,r,i:longint;
  begin
    if deep[x]<deep[y] then begin i:=x;x:=y;y:=i;end;
    i:=0;
    while i>=0 do
    begin
      while deep[d[x][i]]>=deep[y] do begin x:=d[x][i];inc(i); end;
      dec(i);
    end;
    i:=0;
    while f[x]<>f[y] do
    begin
      while d[x][i]<>d[y][i] do
      begin x:=d[x][i];
            y:=d[y][i];
            inc(i);
      end;
      dec(i);
    end;
    exit(f[x]);
  end;
//
Procedure Solve;
  var i,x,y:longint;
  begin
    readln(q);
    for i:=1 to q do
    begin readln(x,y);
          if bcj(x)=bcj(y) then writeln(p[Lca(x,y)]) else writeln(-1);
    end;
  end;
//
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  //
  Init;
  Make_tree;
  Solve;
  //
  close(input);close(output);
end.