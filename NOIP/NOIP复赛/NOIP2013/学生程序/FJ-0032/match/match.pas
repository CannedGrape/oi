var
  a,b,c:array[0..100000]of int64;
  d:array[0..2000,1..2000]of int64;
  f:array[0..2000,1..2000]of int64;
  n,i,j:longint;
begin
  assign(input,'match.in');
  assign(output,'match.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do
  begin
    c[i]:=c[i-1]+(a[i+1]-b[i])*(a[i+1]-b[i]);
  end;
  for i:=1 to n do
  begin
    for j:=1 to i do
    begin
      d[i,j]:=c[i]-c[j-1];
    end;
  end;
  f[0,1]:=0;
  f[0,2]:=0;
  f[1,1]:=(a[1]-b[1])*(a[1]-b[1]);
  f[1,2]:=0;
  for i:=2 to n do
  begin
    f[i,1]:=f[i-1,1]+(a[i]-b[i])*(a[i]-b[i]);
    f[i,2]:=f[i-1,2];
    for j:=1 to i-1 do
    begin
      if f[j-1,1]+d[i,j]+(a[i]-b[j])*(a[i]-b[j])<f[i,1] then
      begin
        f[i,1]:= f[j-1,1]+d[i,j]+(a[i]-b[j])*(a[i]-b[j]);
        f[i,2]:=f[j,2]+i-j;
      end
      else if( (f[j-1,1]+d[i,j]+(a[i]-b[j])*(a[i]-b[j]))=f[i,1]) and (f[j,2]+i-j<f[i,2]) then
      f[i,2]:=f[j,2]+i-j;
    end;
  end;
  writeln(f[n,2] mod 99999997);
  close(input);
  close(output);
end.
