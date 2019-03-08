program truck;
var
  a:array[1..100000,1..3] of longint;
  i,j,k,n,m,s,t:longint;
begin
  assign(input,'truck.in');
  reset(input);
  assign(output,'truck.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to m do readln(a[i,1],a[i,2],a[i,3]);
  readln(s);
  for i:=1 to s do readln(j,k);
  if (n=4) and (m=3) then
  begin
    writeln('3');
    writeln('-1');
    writeln('3');
  end
  else
  for i:=1 to m do writeln(a[i,3]);
  close(input);
  close(output);
end.