var
    a:array[1.. 100000]of longint;
    f:array[0.. 100000,1..2]of longint;
    mark:array[1..100000,1..2]of boolean;
    n,i,j,ans:longint;
function min(a,b:longint):longint;
begin
  if b=0 then exit(a);
  if a<b then exit(a) else exit(b);
end;
function max(a,b:longint):longint;
begin
  if b=0 then exit(a);
  if a>b then exit(a) else exit(b);
end;
begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input);
  rewrite(output);
  read(n);
  for i:=1 to n do
    read(a[i]);
  f[0,1]:=-maxlongint;f[0,2]:=maxlongint;
  for i:=1 to n do
  for j:=1 to i do
    begin
      if (a[i]<f[j-1,2])and(f[j-1,1]<>0) then
        begin
          f[j,1]:=min(a[i],f[j,1]);
          mark[j,1]:=true;
        end;
      if (a[i]>f[j-1,1])and(f[j-1,1]<>0) then
        begin
          f[j,2]:=max(a[i],f[j,2]);
          mark[j,2]:=true;
        end;
    end;
  for i:=1 to n do
    begin
      if mark[i,1] then ans:=i;
      if mark[i,2] then ans:=i;
    end;
  writeln(ans);
  close(input);
  close(output);
end.
