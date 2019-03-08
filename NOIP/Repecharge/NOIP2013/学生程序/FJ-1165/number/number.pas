var
  n,p,i,j,ans:longint;
  a:array[1..1000005] of record
  a,b,c:longint;
  end;

function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;

begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  read(n,p);
  for i:=1 to n do
  read(a[i].a);
  j:=a[1].a;
  a[1].b:=a[1].a;
  for i:=2 to n do
  begin
    a[i].b:=max(j+a[i].a,j);
    j:=a[i].b;
  end;
  a[1].c:=a[1].b;
  j:=a[1].c+a[1].b;
  for i:=2 to n do
  begin
    a[i].c:=j;
    j:=max(j,a[i].b+a[i].c);
  end;
  ans:=-2000000000;
  for i:=1 to n do
    if a[i].c>ans then ans:=a[i].c;
  writeln(ans mod p);
  close(input);
  close(output);
end.
