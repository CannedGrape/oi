var
  n,x,i,j,p,k,max:longint;
  a,b,c,s,max1,max2:array[1..1000]of longint;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  max:=-999999;
  for i:=1 to n do
  begin
  read(a[i]);
  b[i]:=a[i];
  s[i]:=b[i];
  end;


  for i:=2 to n do
  begin
  k:=i;
  while k<>1 do
  begin
   b[i]:=b[i]+a[k-1];
   if s[i]>b[i] then b[i]:=s[i];

   k:=k-1;
  end;
  end;




  c[1]:=b[1]; max1[1]:=c[1]+b[1];
  c[2]:=c[1]+b[1]; max1[2]:=c[2]+b[2];

  for i:=3 to n do
  begin
  k:=i;
       for j:=1 to k-1 do
       if max1[j]>max then max:=max1[j];
  c[i]:=max;
  max1[i]:=c[i]+b[i];
  max:=-999999;
  end;
   for i:=1 to n do
   if max<c[i] then max:=c[i];

   writeln(max mod p);
  close(input);close(output);
end.
