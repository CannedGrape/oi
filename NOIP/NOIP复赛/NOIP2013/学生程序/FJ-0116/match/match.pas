var
  i,j,n,t,s,p:longint;
  a,b,e,f:array[1..100000] of longint;
begin
  assign(input,'match.in'); reset(input);
  assign(output,'match.out'); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    e[i]:=i;f[i]:=i;
    end;
    readln;
  for i:=1 to n do
    read(b[i]);
  for i:=1 to n do
    for j:=i+1 to n do
    begin
    if a[i]>a[j] then
    begin
    p:=a[i]; a[i]:=a[j]; a[j]:=p;
    p:=e[i]; e[i]:=e[j]; e[j]:=p;
    end;
    if b[i]>b[j] then
    begin
    p:=b[i]; b[i]:=b[j]; b[j]:=p;
    p:=f[i]; f[i]:=f[j]; f[j]:=p;
    end;
    end;
  for i:=n downto 1 do
    if e[i]<>f[i] then
    begin
    t:=b[e[i]];b[e[i]]:=b[f[i]];b[f[i]]:=t;inc(s);
    end;
  dec(s);
  writeln(s mod 99999997);
  close(input); close(output);
end.
