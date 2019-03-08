var s,i,n:longint;
    a:array[1..100005]of longint;
procedure work(l,r:longint);
var i,min,l1,r1:longint;
    t:boolean;
begin
  t:=true;
  for i:=l to r-1 do
    if a[i]<>a[i+1] then begin t:=false; break; end;
  if t then
    begin s:=s+a[i];
          for i:=l to r do a[i]:=0; exit; end;
  min:=10001;
  for i:=l to r do
    if min>a[i] then min:=a[i];
  s:=s+min;
  for i:=l to r do a[i]:=a[i]-min;
  r1:=1;
  while (a[r1]=0) and (r1<=r) do inc(r1);
  while r1<=r do
    begin
      l1:=r1;
      while a[r1]<>0 do inc(r1);
      work(l1,r1-1);
      while (a[r1]=0) and (r1<=r) do inc(r1);
    end;
end;

begin
assign(input,'block.in'); reset(input);
assign(output,'block.out'); rewrite(output);

  readln(n);
  s:=0;
  for i:=1 to n do
    begin read(a[i]); end;
  work(1,n);
  writeln(s);

close(input);
close(output);
end.