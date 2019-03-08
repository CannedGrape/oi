var
  n,i,j,low,ans,t:longint;
  a,b:array[0..10000]of longint;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);ans:=0;
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  for i:=1 to n-1 do
  begin
    if (a[i]-b[i]>a[i+1]-b[i])then begin
    t:=a[i];a[i]:=a[i+1];a[i+1]:=t;inc(ans);
  end;
  end;
  write(ans mod 99999997);
  close(input);close(output);
end.
