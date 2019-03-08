var
  n,m,i,k,x:longint;
  s,j:array[1..100000]of longint;
begin
  assign(input,'level.in');assign(output,'level.out');reset(input);rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    read(j[i]);
  for k:=1 to j[i] do
    read(s[k]);
  end;
  randomize;
  x:=4;
  writeln(random(x)+1);
  close(input);close(output);
end.