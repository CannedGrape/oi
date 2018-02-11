var
  p,n,i,j:longint;
  a:array[1..1000000]of longint;
  f,t:array[1..1000000]of int64;
  max:int64;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  f[1]:=a[1];
  for i:=2 to n do
    if a[i]<a[i]+f[i-1] then f[i]:=a[i]+f[i-1] else f[i]:=a[i];
  t[1]:=f[1];t[2]:=t[1]+f[1];
  for i:=3 to n do
    if t[i-1]<f[i-1]+t[i-1] then t[i]:=t[i-1]+f[i-1] else t[i]:=t[i-1];
  max:=t[1];
  for i:=2 to n do if t[i]>max then max:=t[i];
  if max>=0 then begin max:=max mod p;writeln(max);end
  else begin write('-');max:=abs(max);max:=max mod p;writeln(max);end;
  close(input);
  close(output);
end.
