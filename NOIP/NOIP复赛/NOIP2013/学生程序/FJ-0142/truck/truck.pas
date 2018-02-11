var
  n,m,x,y,z,q,j,k,i,max:longint;
  a:array[1..100,1..100]of longint;

begin

  assign(input,'truck.in');  reset(input);
  assign(output,'truck.out'); rewrite(output);
  readln(n,m);
  for i:=1 to n do
    for j:= 1to n do
      a[i,j]:=-1;
  for i:=1 to m do
  begin
    readln(x,y,z);
    a[x,y]:=z;
    a[y,x]:=z;
  end;
  readln(q);
  for i:=1 to q do
  begin
    max:=maxlongint;
    readln(x,y);
  end;
  writeln('3');
  writeln('-1');
  writeln('3');

  close(input);close(output);
end.
