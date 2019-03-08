var
  i,j,n,s:longint;
  a:array[0..100000] of longint;
  b:array[1..100000] of boolean;
begin
  assign(input,'flower.in'); reset(input);
  assign(output,'flower.out'); rewrite(output);
  readln(n);
  fillchar(b,sizeof(b),true);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n div 2 do
    if (a[2*i]<a[2*i-1]) and (a[2*i]<a[2*i+1]) or (a[2*i]>a[2*i-1]) and (a[2*i]>a[2*i+1]) then
    begin inc(s);b[2*i]:=false;end;
  for i:=1 to n do
    if (a[2*i-1]<a[2*i]) and (a[2*i-1]<a[2*i-2]) or (a[2*i-1]>a[2*i]) and (a[2*i-1]>a[2*i-2]) then
    begin inc(s);b[2*i-1]:=false;end;
  if b[1] then inc(s);
  if b[n] then inc(s);
  if s=0 then writeln(1) else
  if s mod 2=0 then begin dec(s);writeln(s);end
  else writeln(s);
  close(input); close(output);
end.


