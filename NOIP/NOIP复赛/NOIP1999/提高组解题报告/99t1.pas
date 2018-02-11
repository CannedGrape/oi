const
  maxn=100;
var
  m,f:array[1..maxn] of integer;
  n:integer;

procedure task1;
var best,i,j:integer;
begin
  for i:=1 to n do f[i]:=1;
  for i:=n-1 downto 1 do
    for j:=i+1 to n do
      if (m[j]<=m[i])and(f[i]<f[j]+1) then
        f[i]:=f[j]+1;
  best:=0;
  for i:=1 to n do if f[i]>best then best:=f[i];
  writeln(best);
end;

function find(k:integer):integer;
var
  best:integer;
  i,p:integer;
begin
  best:=0;
  for i:=k to n do
    if m[i]>best then
    begin
      best:=m[i];
      p:=i;
    end;
  if best=0 then find:=0 else find:=p;
end;

procedure task2;
var
  tot:integer;
  left,p:integer;
begin
  tot:=0; left:=n;
  while left>0 do
  begin
    p:=0;
    while true do
    begin
      p:=find(p+1);
      if p=0 then break;
      m[p]:=0;
      dec(left);
    end;
    inc(tot);
  end;
  writeln(tot);
end;

begin
  n:=0;
  writeln('Input heights(1 line only):');
  repeat
    inc(n);
    read(m[n]);
  until eoln;
  task1;
  task2;
end.
