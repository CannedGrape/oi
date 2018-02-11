program flower;
var
 a:array[1..100000]of int64;
 n,i,j,sum:longint;
begin
 assign(input,'flower.in'); reset(input);
 assign(output,'flower.out'); rewrite(output);
 readln(n);
 sum:=n;
 for i:=1 to n do read(a[i]);
 i:=2;
 j:=1;
 repeat
  while a[i-1]=a[i] do
  begin
   sum:=sum-1;
   inc(i);
  end;
  if a[i]>a[i-1] then
  begin
   while a[i]>a[i-1] do
   begin
    inc(i);
    inc(j);
   end;
  end
  else begin
   while (a[i]<a[i-1])and(i<=n) do
   begin
    inc(i);
    inc(j);
   end;
  end;
  if j>2 then sum:=sum-j+2;
  j:=1;
 until i>=n;
 writeln(sum);
 close(input); close(output);
end.
