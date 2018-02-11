program s3;
var
  a,b,c:array[1..1000] of longint;
  i,j,k,n,p,now,max:longint;
begin
  {assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);}
  readln(n,p);
  b[1]:=-9999;
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    for j:=1 to i do
    begin
      for k:=j to i do
        now:=now+a[k];
      if now>b[i] then b[i]:=now;
      now:=0;
    end;
  c[1]:=b[1];
  for i:=2 to n do
    for j:=1 to i-1 do
    begin
      now:=b[j]+c[j];
      if now>c[i] then c[i]:=now;
    end;
  max:=c[1];
  for i:=1 to n do
    if c[i]>max then max:=c[i];
  max:=max mod p;
  writeln(max);
  {close(input);
  close(output);}
end.
