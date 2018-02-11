var
  n,m,i,j,a,b:longint;
begin
  assign(input,'level.in');assign(output,'level.out');
  reset(input);rewrite(output);
  readln(n,m);
  for i:=1 to m do
   begin
     read(a);
     for j:=1 to a do read(b);
     readln;
   end;
  writeln(m);
  close(input);close(output);
end. 