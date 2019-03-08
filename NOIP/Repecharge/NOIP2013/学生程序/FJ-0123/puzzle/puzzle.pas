const
  l:array [1..4] of longint=(0,0,1,-1);
  r:array [1..4] of longint=(1,-1,0,0);
var
  a,b,p:array [0..100,0..100] of longint;
  his:array[0..1000000,1..3] of longint;
  v,f:array [0..31,0..31,1..4] of longint;
  x1,x2,x3,y1,y2,y3,u1,u2,u3,v1,v2,v3,i,j,m,n,q,left,right,ans,x:longint;
function min(p1,p2:longint):longint;
begin
  if p1>p2 then min:=p2 else min:=p1;
end;
begin
  assign(input,'puzzle.in');
  assign(output,'puzzle.out');
  reset(input);
  rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
  begin
    for j:=1 to m do
    read(a[i,j]);
    readln;
  end;
  b[1,1]:=2;
  b[1,2]:=3;
  b[1,3]:=4;

  b[2,1]:=1;
  b[2,2]:=3;
  b[2,3]:=4;

  b[3,1]:=4;
  b[3,2]:=1;
  b[3,3]:=2;

  b[4,1]:=3;
  b[4,2]:=1;
  b[4,3]:=2;
  for i:=1 to q do
  begin
    readln(x1,y1,x2,y2,x3,y3);
    if (x2=x3)and(y2=y3) then writeln(0) else
    begin
    a[x2,y2]:=0;
    his[1,1]:=x1;
    his[1,2]:=y1;
    fillchar(p,sizeof(p),0);
    left:=1;
    right:=1;
    while left>=right do
    begin
      v1:=his[right,1];
      v2:=his[right,2];
      for j:=1 to 4 do
      begin
        u1:=v1+l[j];
        u2:=v2+r[j];
      if (a[u1,u2]=1)and(p[u1,u2]=0)and((u1<>x1)or(u2<>x2)) then
      begin
        p[u1,u2]:=p[v1,v2]+1;
        inc(left);
        his[left,1]:=u1;
        his[left,2]:=u2;
      end;
      end;
      inc(right);
    end;
    left:=0;
    a[x2,y2]:=1;
    fillchar(f,sizeof(f),63);
    for j:=1 to 4 do
    if (p[x2+l[j],y2+r[j]]>0)or(x1=x2+l[j])and(y1=y2+r[j]) then
    begin
      inc(left);
      his[left,1]:=x2;
      his[left,2]:=y2;
      his[left,3]:=j;
      f[x2,y2,j]:=p[x2+l[j],y2+r[j]];
      v[x2,y2,j]:=1;
    end;
    right:=1;
    while left>=right do
    begin
      v1:=his[right,1];
      v2:=his[right,2];
      v3:=his[right,3];
        x:=b[v3,1];
        u1:=v1-l[x];
        u2:=v2-r[x];
        u3:=x;
        if f[u1,u2,u3]>f[v1,v2,v3]+1 then
        begin
          f[u1,u2,u3]:=f[v1,v2,v3]+1;
          if v[u1,u2,u3]=0 then
          begin
            inc(left);
            his[left,1]:=u1;
            his[left,2]:=u2;
            his[left,3]:=u3;
            v[u1,u2,u3]:=1;
          end;
        end;
        x:=b[v3,2];
        u1:=v1-l[x];
        u2:=v2-r[x];
        u3:=x;
        if (a[u1,u2]=1)and(a[u1+l[v3],u2+r[v3]]=1)and(f[u1,u2,u3]>f[v1,v2,v3]+3) then
        begin
          f[u1,u2,u3]:=f[v1,v2,v3]+3;
          if v[u1,u2,u3]=0 then
          begin
            inc(left);
            his[left,1]:=u1;
            his[left,2]:=u2;
            his[left,3]:=u3;
            v[u1,u2,u3]:=1;
          end;
        end;
        x:=b[v3,3];
        u1:=v1-l[x];
        u2:=v2-r[x];
        u3:=x;
        if (a[u1,u2]=1)and(a[u1+l[v3],u2+r[v3]]=1)and(f[u1,u2,u3]>f[v1,v2,v3]+3) then
        begin
          f[u1,u2,u3]:=f[v1,v2,v3]+3;
          if v[u1,u2,u3]=0 then
          begin
            inc(left);
            his[left,1]:=u1;
            his[left,2]:=u2;
            his[left,3]:=u3;
            v[u1,u2,u3]:=1;
          end;
        end;
      v[v1,v2,v3]:=0;
      inc(right);
    end;
    ans:=1000000;
    for j:=1 to 4 do ans:=min(ans,f[x3,y3,j]);
    if ans=1000000 then writeln(-1) else writeln(ans);
    end;
  end;
  close(input);
  close(output);
end.















