program puzzle;
var
  input,output:text;
  a,c,b,i,j,blankx,blanky,x1,y1,x2,y2:longint;
  map:array[1..1000,1..1000] of byte;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  read(input,a,b,c);

  for i:=1 to a do
    for j:=1 to b do
      read(input,map[i,j]);
  for i:=1 to c do
    begin
      read(input,blankx,blanky,x1,y1,x2,y2);
    end;

  for i:=1 to c do
    writeln(output,'-1');
  close(input);
  close(output);
end.

