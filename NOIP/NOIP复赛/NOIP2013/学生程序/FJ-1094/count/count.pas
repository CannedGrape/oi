var
  n,x,m,i,j,k:longint;
  a,b,c,d,e,f:array[1..1000000]of longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  for i:=1 to n do
  begin
    a[i]:=i;
  end;
  for i:=1 to n do
  begin
    b[i]:=-1;
    c[i]:=-1;
    d[i]:=-1;
    e[i]:=-1;
    f[i]:=-1;
    if a[i]>100000 then b[i]:=a[i] div 100000;
    if a[i]>100000 then a[i]:=a[i] mod 100000;
    if (100000>a[i])and(a[i]>=10000) then c[i]:=a[i] div 10000;
    if (100000>a[i])and(a[i]>=10000) then a[i]:=a[i] mod 10000;
    if (10000>a[i])and(a[i]>=1000) then d[i]:=a[i] div 1000;
    if (10000>a[i])and(a[i]>=1000) then a[i]:=a[i] mod 1000;
    if (1000>a[i])and(a[i]>=100) then e[i]:=a[i] div 100;
    if (1000>a[i])and(a[i]>=100) then a[i]:=a[i] mod 100;
    if (100>a[i])and(a[i]>=10) then f[i]:=a[i] div 10;
    if (100>a[i])and(a[i]>=10) then a[i]:=a[i] mod 10;
    if a[i]=x then m:=m+1;
    if b[i]=x then m:=m+1;
    if c[i]=x then m:=m+1;
    if d[i]=x then m:=m+1;
    if e[i]=x then m:=m+1;
    if f[i]=x then m:=m+1;
  end;
  writeln(m);
  close(input);
  close(output);
end.
