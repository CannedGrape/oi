var
  n,p,i,j,k,max:longint;
  tz,fs,s:array[1..1000000]of longint;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do begin
    read(s[i]);
    for j:=1 to i do
      tz[i]:=tz[i]+s[j];end;
  fs[1]:=tz[1];
  for j:=2 to n do begin
    max:=-10000000000;
    for k:=1 to j-1 do
      if fs[k]+tz[k]>max then max:=fs[k]+tz[k];
    fs[j]:=max;end;
  max:=-10000000000;
  for i:=1 to n do
    if fs[i]>max then max:=fs[i];
  writeln(max mod p);
  close(input);close(output);
end.
