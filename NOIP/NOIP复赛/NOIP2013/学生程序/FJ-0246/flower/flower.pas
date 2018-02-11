program flower;
var n,i,j,count1,count2:longint;
  h,a,b:array[0..1000000]of longint;
function max(k1,k2:longint):longint;
 begin
 if k1>k2 then exit(k1) else exit(k2);
 end;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  reset(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  h[0]:=0;h[n+1]:=0;
  for j:=0 to n+1 do
   begin
    a[j]:=h[j];
    b[j]:=h[j];
   end;
  i:=1;count1:=0;
  while i<=n do
   if (a[i]<a[i-1]) or (a[i]<a[i+1]) then
    begin
      a[i]:=a[i-1];
      a[i-1]:=0;
      inc(i);
    end else
     inc(i,2);
  for j:=1 to n do
  if a[j]<>0 then
    inc(count1);
  i:=2;count2:=0;
  while i<=n do
   if (b[i]<b[i-1]) or (b[i]<b[i+1]) then
    begin
      b[i]:=b[i-1];
      b[i-1]:=0;
      inc(i);
    end else
     inc(i,2);
   for j:=1 to n do
    if b[j]<>0 then
     inc(count2);
 writeln(max(count1,count2)+1);
 readln;readln;
close(input);
close(output);
end.

