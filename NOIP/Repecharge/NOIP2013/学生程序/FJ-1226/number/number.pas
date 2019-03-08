var a:array[1..1000000] of longint;
    f:array[1..1000000,1..3] of longint;
    i,j,n,p,max,val:longint;
begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
 read(n,p);
 for i:=1 to n do
  read(a[i]);
 f[1,1]:=a[1];f[1,2]:=a[1];f[1,3]:=(f[1,1]+f[1,2]) mod p;
 for i:=2 to n do
  begin
   max:=-maxlongint;val:=0;f[i,2]:=-maxlongint;
   for j:=i-1 downto 1 do
    begin
     inc(val,a[j]);
     if val>max then max:=val;
    end;
   f[i,1]:=(a[i]+max) mod p;
   for j:=i-1 downto 1 do
    if f[j,3]>f[i,2] then f[i,2]:=f[j,3];
   f[i,3]:=(f[i,1]+f[i,2]) mod p;
  end;max:=-maxlongint;
 for i:=1 to n do
  if f[i,2]>max then max:=f[i,2];
 write(max mod p);
close(input);close(output);
end.
