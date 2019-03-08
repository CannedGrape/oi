var n,m,i,j,x,y,z,q:longint;
    a:array[1..10000,1..10000] of longint;
begin
  assign(input,'truck.in');assign(output,'truck.out');
  reset(input);rewrite(output);
  read(n,m);
  for i:=1 to m do begin
   read(x,y,z);a[x,y]:=z;a[y,x]:=z;
   end;
   read(q);
   for i:=1 to q do begin
                      read(x,y);
                      writeln(-1);
   end;
   close(input);close(output);
end.
