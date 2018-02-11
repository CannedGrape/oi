var
  a,b,i,j,n:longint;
function cf(m:longint):longint;
var
  d:integer;
begin
  cf:=1;
  if m=0 then cf:=1
  else for d:=1 to m do cf:=cf*10;
end;
function long(x:longint):longint;
var
  z:longint;
  c:boolean;
begin
  z:=-1 ;
  c:=true;
  long:=0;
  while c do
  begin
    z:=z+1;
    if (x div cf(z))>0 then
    begin
      long:=long+1;
    end
    else c:=false;
  end;
end;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(a,b);
  n:=0;
  for i:=1 to a do
  begin
    if i=b then n:=n+1
    else
    for j:=0 to long(i)-1 do
    begin
      if j>0 then if ((i-i mod cf(j)-(i div cf(j+1))*cf(j)))div cf(j)=b then n:=n+1;
      if j=0 then if (i mod cf(1))=b then n:=n+1;
    end;
  end;
  write(n);
  close(input);
  close(output);
end.

