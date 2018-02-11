program ex;
  var a,b,c,d:array[0..1000000]of longint;
      i,j,k,n,l,t,p,max:longint;
  begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
   readln(n,p);
   for i:=1 to n do
    read(a[i]);
   b[1]:=a[1];
   b[2]:=a[2]+b[1];
   if b[1]>b[2] then
    max:=b[1]
   else max:=b[2];
   for i:=3 to n do
    begin
     b[i]:=max+a[i];
     max:=b[i];
    end;
   c[1]:=b[1];
   for i:=2 to n do
    c[i]:=(c[i-1]+b[i-1])mod p;
   max:=-maxlongint;
   for i:=1 to n do
    if c[i]>max then max:=c[i];
   write(max);
  close(input);
  close(output);
  end.