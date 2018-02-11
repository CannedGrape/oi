var
  n,m,i,j,max,t,sum:longint;
  a:array[1..1000,1..1000]of longint;
  x:array[1..1000]of longint;
  p:array[0..1000]of longint;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      read(x[i]);
      for j:=1 to x[i] do
        begin
          read(a[i,j]);
          if (j>1)and(j<x[i]) then begin inc(p[a[i,j]]);if max<a[i,j] then max:=a[i,j];end;
        end;
    end;
  for i:=1 to max-1 do
    for j:=i+1 to max do
      if p[i]<p[j] then begin t:=p[i];p[i]:=p[j];p[j]:=t;end;
  for i:=1 to max do
    if p[i]<>p[i-1] then inc(sum);
  writeln(sum-1);
  close(input);
  close(output);
end.