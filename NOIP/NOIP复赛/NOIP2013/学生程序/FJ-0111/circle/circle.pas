var
  a:array[0..1000000]of longint;
  b:array[0..1000000]of longint;
  t:int64;
  i,j,l,y,n,m,k,x,q:longint;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);t:=1;
  for i:=0 to n-1 do
    a[i]:=i;
  for j:=1 to k do
    t:=t*10;
  if n mod m=0  then q:=n div m
  else  q:=n;
  t:=t mod q;
  if t=0 then b[x]:=a[x]
  else
  begin
    for i:=1 to t do
    begin
      for j:=0 to n-1 do
        begin
          l:=j+m;
          if l>=n then l:=l-n;
          b[l]:=a[j];
        end;
      for y:=0 to n-1 do
        a[y]:=b[y];
    end;
  end;
  writeln(b[x]);
  close(input);
  close(output);
end.
