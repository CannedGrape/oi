var
  max1,max2,i,j,n,m,p:longint;
  a,t,f,s,sum:array[0..1000001] of longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do begin read(a[i]);end;
  max2:=-maxlongint;
  sum[1]:=a[1];t[1]:=a[1];max2:=a[1];
  for i:=2 to n do
  begin
    sum[i]:=max(sum[i-1]+a[i],a[i]);
    if sum[i]>max2 then max2:=sum[i];
    t[i]:=max2;
  end;
  f[1]:=t[1];s[1]:=f[1]+t[1];
  max1:=s[1];
  for i:=2 to n do
  begin
    f[i]:=max1;
    s[i]:=f[i]+t[i];
    if (s[i]>max1)and (i<>n) then max1:=s[i];
  end;
  max1:=-maxlongint;
  for i:=1 to n do if f[i]>max1 then max1:=f[i];
  if max1<0 then
  begin
    if abs(max1) mod p<>0 then
      write('-',abs(max1)mod p)
    else write(0);
  end
  else write(max1 mod p);
  close(input);
  close(output);
end.
