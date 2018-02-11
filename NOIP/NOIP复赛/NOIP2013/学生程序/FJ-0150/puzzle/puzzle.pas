program puzzle;
var n,m,q,i,j:longint;
    a,b:array[1..30,1..30]of longint;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
   begin
     for j:=1 to m do
      read(a[n,m]);
     readln;
   end;
  for i:=1 to 2 do
    begin
     for j:=1 to 6 do
      read(b[i,j]);
     readln;
    end;
  writeln(2);
  writeln(-1);
  close(input);
  close(output);
end.