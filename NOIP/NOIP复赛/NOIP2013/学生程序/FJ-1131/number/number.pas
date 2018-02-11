var
  n,i,j,p,a,max:longint;
  shou,tzh,tz,fs:array [0..1000000] of longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
    read(shou[i]);
  tzh[1]:=shou[1];
  for i:=2 to n do
    if shou[i]+tzh[i-1]>=shou[i] then tzh[i]:=tzh[i-1]+shou[i] else tzh[i]:=shou[i];
  tz[1]:=tzh[1];
  for i:=2 to n do
    if tzh[i]>tz[i-1] then tz[i]:=tzh[i] else tz[i]:=tz[i-1];
  fs[1]:=tz[1];
  fs[2]:=fs[1]+tz[1];
  if fs[2]>fs[1] then max:=fs[2] else max:=fs[1];
  fs[0]:=-maxlongint+1;
  for i:=3 to n do
    begin
      a:=tz[i-1]+fs[i-1];
      if a>fs[i-1] then fs[i]:=a else fs[i]:=fs[i-1];
      if fs[i]>max then max:=fs[i];
    end;
  writeln(max mod p);
  close(input);
  close(output);
end.