var i,j:longint;a,tz:array[1..1000000]of int64;n,p,s,max:int64;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  tz[1]:=a[1];tz[2]:=a[1]+a[2];
  for i:=3 to n do
  begin
  for j:=1 to i do
  begin
    s:=s+a[j];
    if s>max then max:=s;
    if s<0 then s:=0;
  end;
    tz[i]:=max;s:=0;
    max:=0;
  end;
  a[1]:=tz[1];a[2]:=a[1]+tz[1];
  if (a[2]+tz[2])>(a[1]+tz[1])then max:=a[2]+tz[2]
  else max:=a[1]+tz[1];
  if a[1]<a[2]then s:=a[2]
  else s:=a[1];
  for i:=3 to n do
  begin
    a[i]:=max;
    if max<(a[i]+tz[i])then max:=a[i]+tz[i];
    if a[i]>s then s:=a[i] mod p;
  end;
  writeln(s);
  close(input);close(output);
end.
