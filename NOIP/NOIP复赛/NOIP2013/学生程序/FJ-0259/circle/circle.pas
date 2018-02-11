var
  r,i,b,c,d,n,m,k,x:longint;
  a:array[1..1000000]of longint;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  read(n,m,k,x);
  for i:=0 to n-1 do a[i]:=i;
  b:=1;
  c:=-1;
  for i:=1 to k do b:=b*10;
  for i:=1 to b do
  begin
    c:=c+1;
    c:=c mod n;
    d:=a[c];
    for r:=0 to m-1 do a[(c+r)mod n]:=a[(c+r+1)mod n];
    a[(c+m)mod n]:=d;
  end;
  for i:=0 to n-1 do if a[i]=x then write(i);
  readln;readln;
  close(input);
  close(output);
end.
