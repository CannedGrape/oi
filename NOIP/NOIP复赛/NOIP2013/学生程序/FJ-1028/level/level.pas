program level;
var n,m,i,s,l,j,h,t:integer;
  a:array[1..1000,1..1000]of integer;
  c,b:array[1..1000]of longint;

begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  read(n,m);
  for i:=1 to m do
  begin
    readln;
    read(s);
    for j:=1 to s do
    begin
      read(l);
      inc(a[i,l]);
    end;
  end;
  for i:=1 to n do
    for j:=1 to m do
    begin
      b[i]:=b[i]+a[i,j]*sqr(j*100+j);
    end;
  c[1]:=b[1];
  h:=1;
  for i:=2 to n do
  begin
    t:=1;
    for j:=1 to h do
    begin
      if b[i]=c[j] then t:=0;
    end;
    if t=1 then begin
      h:=h+1;
      c[h]:=b[i];
    end;
  end;
  rewrite(output);
  writeln(h mod 2+1);
  close(input);
  close(output);
end.

