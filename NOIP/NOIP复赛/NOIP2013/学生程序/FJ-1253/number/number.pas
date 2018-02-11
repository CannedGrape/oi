var a,q,b:array[1..1000000]of longint;
    max,sum,i,j,s,n,maxmax,p:longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  q[1]:=a[1];
  i:=2;
  repeat
    max:=-maxlongint;sum:=0;
    for j:=1 to i do
    begin
      sum:=sum+a[j];
      if sum>max then max:=sum;
    end;
    q[i]:=max;
    inc(i);
  until i>n;
  i:=2;b[1]:=q[1];
  repeat
    max:=-maxlongint;
    for j:=1 to i-1 do
    begin
      if b[j]+q[j]>max then max:=b[j]+q[j];
    end;
    b[i]:=max;
    inc(i);
  until i>n;
  max:=-maxlongint;
  for i:=1 to n do if b[i]>max then max:=b[i];
  if max<0 then write('-');
  write(abs(max) mod p);
  close(input);
  close(output);
end.

