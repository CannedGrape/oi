var
  n,i,k,ans,sum,tot:longint;
  f:array[1..100000]of longint;
  d:array[1..100000]of longint;
begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  readln(n);
   if n=1 then
  begin
    writeln(1);
  end;
  tot:=2;
  ans:=0;
  read(f[1]);
  for i:=2 to n do
  begin
    read(f[tot]);
    if f[tot]=f[tot-1] then
    begin
      f[tot]:=0;
      inc(ans);
    end
    else inc(tot);
  end;
  dec(tot);
  for i:=2 to tot do
  begin
    d[i]:=f[i]-f[i-1];
  end;

  if d[2]>0 then k:=1 else k:=-1;
  sum:=1;
  for i:=3 to tot do
  begin
    if d[i]=0 then inc(ans);
    if d[i]*k>0 then inc(ans);
    if d[i]*k<0 then
    begin
      k:=-1*k;
      inc(sum);
    end;
  end;
  if (sum mod 2=0) and ((f[tot]=0) or (d[tot]<0))then dec(ans);
  writeln(n-ans);
end.
