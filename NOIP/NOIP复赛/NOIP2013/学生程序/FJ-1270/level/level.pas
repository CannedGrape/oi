var a:array[1..1000] of longint;
    i,j,k,n,m,s,t:longint;
    f:boolean;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  readln(n,m);
  t:=1;
  for i:=1 to m do
  begin
  read(s);
  f:=true;
  for j:=1 to s do
  begin
  read(k);
  if (a[k]<>1) and (f) then begin inc(t);  f:=false; end;
  a[k]:=1;
  end;
  end;
  write(t);
  close(input);
  close(output);
end.