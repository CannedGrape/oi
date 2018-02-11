var num,tz,mark:array[0..1000000] of longint;
    n,p,i,j,a:longint;
function plus(aa:longint):longint;
var i:longint;
begin
  plus:=0;
  for i:=1 to aa do
    plus:=plus+num[i];
end;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do
    read(num[i]);
  tz[1]:=num[1];
  for i:=2 to n do
    begin
      if num[i]<0 then tz[i]:=tz[i-1];
      if num[i]>=0 then
        begin
          a:=plus(i);
          if a>tz[i-1] then tz[i]:=a
            else tz[i]:=tz[i-1];
        end;
    end;
  mark[1]:=tz[1];
  for i:=2 to n do
    begin
      mark[i]:=-maxlongint;
      for j:=1 to i-1 do
        if tz[j]+mark[j]>mark[i]
          then mark[i]:=tz[j]+mark[j];
    end;
  mark[0]:=-maxlongint;
  for i:=1 to n do
    if mark[i]>mark[0] then mark[0]:=mark[i];
  if mark[0]<0 then write('-',abs(mark[0]) mod p)
    else write(abs(mark[0] mod p));
  close(input);close(output);
end.
