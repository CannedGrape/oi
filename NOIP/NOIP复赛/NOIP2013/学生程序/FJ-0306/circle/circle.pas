program ex_1;
var a:array[0..1000001]of longint;
    b:array[0..2000000]of longint;
    n,m,k,x,i,j,p,t:longint;
begin
  assign(input,'circle.in');reset(input);
  read(n,m,k,x);
  for i:=0 to n-1 do
    a[i]:=i;
  close(input);
  b[0]:=a[x];
  p:=0;
  repeat
    inc(p);
    b[p]:=b[p-1]+m;
    if b[p]>n-1 then b[p]:=b[p]-n;
  until b[p]=a[x];
  t:=1;
  for i:=1 to k do
    begin
      t:=t*10;
      t:=t mod p;
    end;
  assign(output,'circle.out');rewrite(output);
  write(b[t]);
  close(output);
end.

