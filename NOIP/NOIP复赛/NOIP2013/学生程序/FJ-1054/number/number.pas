var
  n,p,i,j,k:longint;
  a:array[1..10000] of longint;
  b:array[1..10000,1..10000] of longint;
  max,max1:int64;
procedure duru;
begin
  readln(n,p);
  for i:=1 to n do
    begin
      read(k);
      b[i,i]:=k;
    end;
  a[1]:=b[1,1];max1:=a[1]+a[1];
  for i:=2 to (n-1) do
    begin
      for j:=1 to (i-1) do
        b[j,i]:=b[j,i-1]+b[i,i];
      max:=b[1,i];
      for j:=1 to i do
        for k:=j to i do
          if b[j,k]>max then
            max:=b[j,k];
      a[i]:=max1;
      if max>0 then
        max1:=a[i]+max;
    end;
  a[n]:=max1;
  max:=a[n];
  for i:=1 to (n-1) do
    if a[i]>max then
      max:=a[i];
  if max<0 then write('-');
  max:=abs(max);
  write(max mod p);
end;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  duru;close(input);close(output);
end.
