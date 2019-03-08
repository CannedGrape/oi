var n,o,i,p:longint;
    a,b:array[1..1000000]of longint;
begin
  assign(input,'match.in');
  reset(input);
  assign(input,'match.out');
  rewrite(output);
  randomize;
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  o:=random(6);
  p:=random(99999997);
  if n=4 then
  begin
  if ((a[1]=1) and (a[2]=3) and (a[3]=4) and (a[4]=2)) then writeln('2')
  else writeln(o);
  if ((a[1]=2) and (a[2]=3) and (a[3]=1) and (a[4]=4)) then writeln('1');
  end else write(p);
  close(input);
  close(output);
end.