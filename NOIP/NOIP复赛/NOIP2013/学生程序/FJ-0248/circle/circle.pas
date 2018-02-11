program circle;

var
  n,m,k,x,i,t,s:longint;
  a:array[1..100000000]of longint;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);

  read(n,m,k,x);
  for i:=0 to n-1 do
    a[i]:=i;

    s:=1;
    for i:=1 to k do begin
      s:=s*10;
      if s>100000000 then s:=s mod 100000000
    end;

    for i:=1 to k do
      x:=(x+m-1) mod n+1;

  writeln(a[x]);
  readln;readln;
  close(input);
  close(output);
end.
