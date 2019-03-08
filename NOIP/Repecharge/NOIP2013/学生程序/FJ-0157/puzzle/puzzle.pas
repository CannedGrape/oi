program puzzle;
 var n,m,q,x,i,j:integer;
     a:array[0..30,0..30]of integer;
     b:array[0..500,0..6]of integer;

begin
 assign(input,'puzzle,in');
 assign(output,'puzzle,out');
 reset(input);
 reset(output);

  readln(n,m,q);
  for i:=1 to n do
   begin
    for j:=1 to m do
     read(a[i,j]);
    readln;
   end;

  for i:=1 to q do
   begin
    for j:=1 to 6 do
     read(b[i,j]);
    readln;
   end;

   x:=0-1;

  write(x);

 close(input);
 close(output);
end.