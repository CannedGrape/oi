program match;
var
  n,j,i,z,k,p:longint;
  a,b,c,d:array[0..100000] of longint;
procedure zhao1;
begin
  for j:=1 to n do
    if a[j]=c[i] then exit;
end;
procedure zhao2;
begin
  for z:=1 to n do
    if a[z]=d[i] then exit;
end;

procedure qsorta(x,y:longint);
var
  i,j,mid,z:longint;
begin
  i:=x;
  j:=y;
  mid:=a[(x+y) div 2];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then
    begin
      z:=a[i];
      a[i]:=a[j];
      a[j]:=z;
      inc(i);
      dec(j);
    end;
  until i>j;
  if x<j then qsorta(x,j);
  if i<y then qsorta(i,y);
end;
procedure qsortb(x,y:longint);
var
  i,j,mid,z:longint;
begin
  i:=x;
  j:=y;
  mid:=b[(x+y) div 2];
  repeat
    while b[i]<mid do inc(i);
    while b[j]>mid do dec(j);
    if i<=j then
    begin
      z:=b[i];
      b[i]:=b[j];
      b[j]:=z;
      inc(i);
      dec(j);
    end;
  until i>j;
  if x<j then qsortb(x,j);
  if i<y then qsortb(i,y);
end;
begin
  assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);
  readln(n);
  k:=0;
  for i:=1 to n do
    begin
    read(a[i]);
    c[i]:=a[i];
    end;
  readln;
  for i:=1 to n do
  begin
    read(b[i]);
    d[i]:=b[i];
  end;
  qsorta(1,n);
  qsortb(1,n);
  for i:=1 to n do
  begin
    zhao1;
    if d[i]<>b[j] then
    begin
      zhao2;
      inc(k);
      p:=d[z];
      d[z]:=d[j];
      d[j]:=z;
    end;
  end;
  writeln(k-1);
  close(input);
  close(output);
end.

