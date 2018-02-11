var i,j,n,m:longint;
    max1,max2,max,k:int64;
    a,h,p:array[0..1000001]of longint;
begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(n,m);
  read(a[1]); max:=a[1]; k:=a[1]; p[1]:=a[1];
  for i:=2 to n do
   begin
    read(a[i]);
    if a[i]+k>0 then k:=a[i]+k
     else k:=-maxlongint;
    if k=-maxlongint then k:=a[i];
    if (k>max) then max:=k;
    p[i]:=max;
   end;
  max2:=p[1]; h[1]:=p[1]; max1:=h[1]+p[1];

  for i:=2to n do
   begin
    h[i]:=max1;
    if p[i]+h[i]>max1 then max1:=p[i]+h[i];
    if h[i]>max2 then max2:=h[i];
   end;
  writeln(max2 mod m);
  close(input); close(output);
end.
