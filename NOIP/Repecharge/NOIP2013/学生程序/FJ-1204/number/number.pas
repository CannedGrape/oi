var n,p,f,max:longint;x,tz,fs:array[1..1000000]of longint;
begin
  assign(input,'number.in');
  reset(input);
  read(n,p);
  for f:=1 to n do read(x[f]);
  close(input);
  assign(output,'number.out');
  rewrite(output);
  tz[1]:=x[1];
  fs[1]:=tz[1];
  max:=0;
  for f:=2 to n do
  begin
    tz[f]:=tz[f-1]+x[f];
  end;
  for f:=2 to n do
  begin
    fs[f]:=tz[f-1]+fs[f-1];
  end;
  for f:=1 to n do
  begin
    if (fs[f]>max) then max:=fs[f];
  end;
  write(max);
  close(output);
end.
