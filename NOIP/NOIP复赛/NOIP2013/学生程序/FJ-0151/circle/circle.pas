Program circle;
  var n,m,k,x,i,j,z:longint;
      a,b:array[0..999999]of longint;

  begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  z:=1;
  read(n,m,k,x);
  for i:=0 to n-1 do
    a[i]:=i;
  for i:=1 to k do
    z:=z*10;
  for i:=1 to z do
    begin
      a[x]:=a[x]+m;
      if a[x]<0 then a[x]:=a[x]-n;
    end;
  writeln(a[x]);
  close(input);
  close(output);
  end.
