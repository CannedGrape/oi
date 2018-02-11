var
  f:array[0..1,0..100000]of longint;
  n,i,min,ans:longint;
begin
  assign(input,'block.in');
  assign(output,'block.out');
  reset(input);
  rewrite(output);
  f[1,0]:=0;
  readln(n);
  f[1,n+1]:=0;
  min:=10000000;
  for i:=1 to n do
  begin
    read(f[1,i]);
    if f[1,i]<min then min:=f[1,i];
    f[0,i]:=f[1,i]-f[1,i-1];
  end;
  f[0,n+1]:=f[1,n+1]-f[1,n];
  ans:=0;
  for i:=1 to n+1 do
  begin
    inc(ans,abs(f[0,i]));
  end;
  writeln(ans div 2);
  close(input);
  close(output);
end.
