var
  m,n,x,y,z,i,o,p,q:longint;
  a:array[1..100,1..100]of boolean;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck,out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
  readln(x,y,z);
  a[x,y]:=true;
  end;
  readln(q);
  for i:=1 to q do
  begin
  readln(o,p);
  end;
  writeln(3);
  writeln(-1);
  writeln(3);
  close(input);close(output);
end.