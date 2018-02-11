var a,t,f:array[1..1000]of int64;
    i,j,n,q:longint;
    max,k:int64;
begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
 readln(n,q);
 for i:=1 to n do read(a[i]);
 fillchar(t,sizeof(t),0);
 t[1]:=a[1];
 k:=a[1];
 for i:=2 to n do
 begin
  if k+a[i]<a[i] then k:=a[i] else k:=k+a[i];
  if t[i-1]>k then t[i]:=t[i-1]
  else t[i]:=k;
 end;
 f[1]:=t[1];
 max:=f[1];
 for i:=2 to n do
 begin
  f[i]:=-maxlongint;
  for j:=1 to i-1 do
  if f[j]+t[j]>f[i] then
  begin
   f[i]:=f[j]+t[j];
  end;
  if f[i]>max then max:=f[i];
  f[i]:=f[i] mod q;
 end;
 max:=max mod q;
 write(max);
 close(input);close(output);
end.