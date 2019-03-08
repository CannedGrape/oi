program level;
var
  n,p,i,j,k,x,y,z:integer;
  a:array[1..1000,1..3] of integer;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  read(n);
  readln(p);
  k:=0;
  z:=0;
  for i:=1 to n do
    read(a[i,1]);
  a[1,2]:=a[1,1];
  for i:=2 to n do
    begin
      x:=-10000;
      for y:=1 to i do
        begin
          for j:=y to i do
            begin
              k:=k+a[j,1];
              if x<k then x:=k;
            end;
          for j:=y downto 1 do
            begin
              z:=z+a[j,1];
              if x<z then x:=z;
            end;
        end;
      a[i,2]:=x;
    end;
  for i:=1 to n do
    a[i,3]:=0;
  for i:=1 to n do
    for j:=1 to i-1 do
      a[i,3]:=a[i,3]+a[j,2];
  x:=a[1,3];
  for i:=2 to n do
    if x<a[i,3] then x:=a[i,3];
  if x<0 then y:=0-x;
  if p<0 then z:=0-p;
  if y<=z then write(y)
          else write(z);
  close(input);
  close(output);
end.
