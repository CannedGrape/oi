var
  s:ansistring;
  i,x,y,z,h:longint;
  a,c:array[1..1000000]of longint;
  b,d:array[1..100000]of string;
  n:set of '0'..'9';
begin
  assign(input);
  reset(input,'expr.in');
  assign(output);
  rewrite(output,'expr.out');
  readln(n,p);
  readln(s);
  x:=1;
  y:=1;
  n:=['0'..'9'];
  while x<=length(s) do
  begin
  while s[x]in n do
  begin
    x:=x+1;
    a[y]:=a[y]*10+1;
  end;
    b[y]:=s[x];x:=x+1;
    y:=y+1;
  end;
  y:=y-1;
  x:=1;
  h:=1;
  z:=0;
  while x<=y-1 do
  begin
    c[h]:=1;
  while b[x]='*' do
  begin
    c[h]:=c[h]*a[x];
    a[x]:=0;
    x:=x+1;
  end;
    if b[x-1]='*' then begin c[h]:=c[h]*a[x];a[x]:=0;  end
    else c[h]:=0;
    x:=x+1;
    z:=z+c[h];
    h:=h+1;
  end;

  for i:=1 to y do
  z:=z+a[i];
  writeln(z);
  close(input);
  close(output);
  readln;readln
end.
