var
  a,b:array[1..100000]of longint;
  x,y,z,i,n,r,o:longint;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  x:=1;
  b[0]:=1000001;
  for i:=1 to n do
  begin
    if x mod 2=1 then
    begin
      if a[i]<b[x-1]then
      begin
        b[x]:=a[i];
        x:=x+1;
      end;
    end;
    if x mod 2=0 then
    begin
      if a[i]>b[x-1]then
      begin
        b[x]:=a[i];
        x:=x+1;
      end;
    end;
  end;
  y:=x-1;
  x:=1;
  b[0]:=0;
  for i:=1 to n do
  begin
    if x mod 2=1 then
    begin
      if a[i]>b[x-1]then
      begin
        b[x]:=a[i];
        x:=x+1;
      end;
    end;
    if x mod 2=0 then
    begin
      if a[i]<b[x-1]then
      begin
        b[x]:=a[i];
        x:=x+1;
      end;
    end;
  end;
  if x>y then write(x)
  else write(y);
  readln;readln;
  close(input);
  close(output);
end.
