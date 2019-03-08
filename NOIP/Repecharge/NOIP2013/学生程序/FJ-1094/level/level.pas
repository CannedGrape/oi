var
  n,m,i,j,k,max:longint;
  a:array[1..1000000]of longint;
  b:array[1..1000000]of longint;
  c:array[1..1000000]of longint;
  min:array[1..100000]of longint;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  a[1]:=3;
  a[2]:=1;
  a[3]:=2;
  a[4]:=1;
  a[5]:=3;
  a[6]:=2;
  a[7]:=1;
  a[8]:=1;
  a[9]:=3;
  readln(n,m);
  for i:=1 to m do
  begin
    read(b[i]);
    min[i]:=10000;
    for j:=1 to b[i] do
    begin
      read(c[j]);
    end;
    readln;
    for j:=1 to b[i] do
    begin
      k:=c[j];
      if a[k]<min[i] then min[i]:=a[k];
    end;
  end;
  for i:=1 to m do
  begin
    if max<min[i] then max:=min[i];
  end;
  writeln(max);
  close(input);
  close(output);
end.

