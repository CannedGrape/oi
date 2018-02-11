var
  i,j,m,n,k,l,r:longint;ans:longint;
  a:array [0..100000] of longint;
  t:boolean;
begin
  assign(input,'flower.in');reset(input);assign(output,'flower.out');rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  i:=1;ans:=1;while (i<n) and (a[i]=a[i+1]) do inc(i);
  repeat
    t:=false;
    while (i<n) and not (a[i+1]<a[i]) do
    begin
      inc(i);
      t:=true;
    end;
    if t then inc(ans);
    t:=false;
    while (i<n) and not (a[i+1]>a[i]) do
    begin
      inc(i);
      t:=true;
    end;
    if t then inc(ans);
  until i=n;
  writeln(ans);
  close(input);close(output);
end.