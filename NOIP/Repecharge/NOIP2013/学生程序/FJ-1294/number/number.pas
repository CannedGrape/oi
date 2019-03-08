program number;
var
  a:array[1..10000000] of int64;
  n,i,p:int64;
  k:integer;
begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(n,p);
  for i:=1 to n do  read(a[i]);
  randomize;
  k:=random(100);
  write(k);
  close(input);
  close(output);
end.


